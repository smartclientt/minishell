/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:16:50 by shbi              #+#    #+#             */
/*   Updated: 2022/12/24 17:02:18 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	first_cmd(int fd[2], int prev_in, int prev_out)
{
	(void)prev_in;
	(void)prev_out;
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		error_msg("error dup first cmd\n");
	close(fd[1]);
}

void	between_cmd(int fd[2], int prev_in, int prev_out)
{
	close(fd[0]);
	close(prev_out);
	//read
	if (dup2(prev_in, 0) == -1)
		error_msg("2-error dup between cmd\n");
	close(prev_in);
	//write
	if (dup2(fd[1], 1) == -1)
		error_msg("1-error dup between cmd\n");
	close(fd[1]);
}

void	last_cmd(int fd[2], int prev_in, int prev_out)
{
	(void)fd;
	close(prev_out);
	if (dup2(prev_in, 0) == -1)
		error_msg("error dup last cmd\n");
	close(prev_in);
}

void	run_cmd(t_env **menv, char **cmd)
{
	int	checker;

	if (is_builted(cmd))
	{
		exec_builted(menv, cmd);
		exit(0);
	}
	else
	{
		checker = check_access_path(cmd[0]);
		if (checker == 1)
		{
			if (execve(cmd[0], cmd, env_to_array(*menv)) == -1)
				perror("minishell");
		}
		else if (checker == -1 || checker == -3)
			exit(126);
		else if (checker == 0 || checker == -2)
			exit(127);
	}
}

void	multi_pipes(t_env **menv, char ***cmd, int cmd_nbr)
{
	int	i;
	int	prev_in;
	int	prev_out;
	int	fd[2];
	int	id;

	prev_in = -1;
	prev_out = -1;
	fd[0] = -1;
	fd[1] = -1;
	i = 0;
	while (i < cmd_nbr)
	{
		prev_in = fd[0];
		prev_out = fd[1];
		if (i + 1 != cmd_nbr)
			pipe(fd);
		id = fork();
		if (id == 0)
		{
			if (1 != cmd_nbr)
			{
				if (i == 0)
					first_cmd(fd, prev_in, prev_out);
				else if (i + 1 == cmd_nbr)
					last_cmd(fd, prev_in, prev_out);
				else
					between_cmd(fd, prev_in, prev_out);
			}
			run_cmd(menv, cmd[i]);
		}
		close(prev_in);
		close(prev_out);
		i++;
	}
	while (wait(&status) != -1);
	if (WIFEXITED(status))
		WEXITSTATUS(status);
	printf("status = %d\n", status % 255);
}
