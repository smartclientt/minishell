/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:16:50 by shbi              #+#    #+#             */
/*   Updated: 2022/11/29 16:10:02 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	first_cmd(int fd[2], int prev_in, int prev_out)
{
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		error_msg("error dup first cmd");
	close(fd[1]);
}

void	between_cmd(int fd[2], int prev_in, int prev_out)
{
	close(fd[0]);
	close(prev_out);
	if (dup2(prev_in, 0) == -1)
		error_msg("error dup between cmd");
	close(prev_in);
	if (dup2(fd[1], 1) == -1)
		error_msg("error dup between cmd");
	close(fd[1]);
}

void	last_cmd(int fd[2], int prev_in, int prev_out)
{
	close(prev_out);
	if (dup2(prev_in, 0) == -1)
		error_msg("error dup last cmd");
	close(prev_in);
}

void	run_cmd(t_env *menv, char **cmd)
{
	if (execve(cmd[0], cmd, menv) == -1)
		error_msg("error execution cmd");
}

void	multi_pipes(t_env *menv, char **cmd, int cmd_nbr)
{
	int	i;
	int	prev_in;
	int	prev_out;
	int	fd[2];
	int id;
	
	prev_in = -1;
	prev_out = -1;
	fd[0] = -1;
	fd[0] = -1;
	i = 0;
	while (i < cmd_nbr)
	{
		if (i + 1 != cmd_nbr)
			pipe(fd);
		prev_in = fd[0];
		prev_out = fd[1];
		id = fork();
		if (id = 0)
		{
			if (i == 0)
				first_cmd(fd, prev_in, prev_out);
			else if (i + 1 == cmd_nbr)
				last_cmd(fd, prev_in, prev_out);
			else
				between_cmd(fd, prev_in, prev_out);
			run_cmd(menv, cmd);
		}
		close(prev_in);
		close(prev_out);
		i++;
	}
	while (wait(NULL) != -1);
}
