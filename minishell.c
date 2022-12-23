/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:50:40 by shbi              #+#    #+#             */
/*   Updated: 2022/12/23 10:28:12 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_env *menv;
	char **str;

	str = malloc(sizeof(char *) * 6);
	str[0] = "../";
	str[1] = "~";
	str[2] = "";
	str[3] = "";
	str[4] = "";
	str[5] = NULL;
	char **cmd1;
	cmd1 = malloc(sizeof(char *) * 3);
	cmd1[0] = "safasfa";
	cmd1[1] = "";
	cmd1[2] = NULL;

	char **cmd2;
	cmd2 = malloc(sizeof(char *) * 3);
	cmd2[0] = "env";
	// cmd2[1] = "";
	cmd2[1] = NULL;

	char **cmd3;
	cmd3 = malloc(sizeof(char *) * 2);
	cmd3[0] = "wc";
	cmd3[1] = NULL;

	char **cmd4;
	cmd4 = malloc(sizeof(char *) * 2);
	cmd4[0] = "wc";
	cmd4[1] = NULL;

	size_t cmds_n = 4;
	char ***cmds = malloc(sizeof(char **) * cmds_n + 1);
	cmds[0] = cmd1;
	cmds[1] = cmd2;
	cmds[2] = cmd3;
	cmds[3] = cmd4;
	cmds[4] = NULL;

	fill_env(&menv, env);
	// printf("----------------------------------\n");
	// b_export(&menv, NULL);
	// b_cd(&menv, str[0]);
	// b_cd(&menv, str[0]);
	// b_pwd(menv);
	printf("----------------------------------\n");
	// multi_pipes(menv, cmds, 2);
	execution(menv, cmds, 1);
	// b_export(&menv, NULL);
	// printf("----------------------------------\n");
	// char	*path;

	// path = check_cmd_access(menv, cmd1[0]);
	// printf("path = %s\n", path);
	// system("leaks minishell");
	return (0);
}
