/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:50:40 by shbi              #+#    #+#             */
/*   Updated: 2022/12/24 10:55:34 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int main(int ac, char **av, char **env)
// {
// 	(void)ac;
// 	(void)av;
// 	t_env *menv;

// 	fill_env(&menv, env);
// 	minishell_loop(menv);
// }

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_env *menv;
	// char **str;

	// str = malloc(sizeof(char *) * 6);
	// str[0] = "../";
	// str[1] = "~";
	// str[2] = "";
	// str[3] = "";
	// str[4] = "";
	// str[5] = NULL;
	char **cmd1;
	cmd1 = malloc(sizeof(char *) * 3);
	cmd1[0] = "unset";
	cmd1[1] = "ZSH";
	cmd1[2] = NULL;

	char **cmd2;
	cmd2 = malloc(sizeof(char *) * 3);
	cmd2[0] = "unset";
	cmd2[1] = "LESS";
	cmd2[2] = NULL;

	char **cmd3;
	cmd3 = malloc(sizeof(char *) * 3);
	cmd3[0] = "unset";
	cmd3[1] = "PWD";
	cmd3[2] = NULL;

	char **cmd4;
	cmd4 = malloc(sizeof(char *) * 3);
	cmd4[0] = "unset";
	cmd4[1] = "PAGER";
	cmd4[2] = NULL;

	size_t cmds_n = 4;
	char ***cmds = malloc(sizeof(char **) * (cmds_n + 1));
	cmds[0] = cmd1;
	cmds[1] = cmd2;
	cmds[2] = cmd3;
	cmds[3] = cmd4;
	cmds[4] = NULL;

	fill_env(&menv, env);
	// printf("%p\n", &menv->key);
	printf("----------------------------------\n");
	// b_export(&menv, NULL);
	// execution(menv, cmds + 1, 1);
	// printf("**********************************\n");
	execution(&menv, cmds, 1);
	printf("key1 = %s\n", menv->key);
	execution(&menv, cmds + 1, 1);
	printf("key2 = %s\n", menv->key);
	execution(&menv, cmds + 2, 1);
	printf("key3 = %s\n", menv->key);
	execution(&menv, cmds + 3, 1);
	printf("key4 = %s\n", menv->key);
	// printf("----------------------------------\n");
	// printf("%p\n", &menv->key);
	// printf("KEY = '%s'\n", menv->key);
	// printf("%p\n", &menv->key);
	// printf("----------------------------------\n");
	b_export(&menv, NULL);
	return (0);
}
