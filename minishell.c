/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:50:40 by shbi              #+#    #+#             */
/*   Updated: 2022/11/23 18:54:12 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_env	*menv;

	char **str;
	str = malloc(sizeof(char *) * 6);
	str[0] = "../";
	str[1] = "~";
	str[2] = "";
	str[3] = "";
	str[4] = "";
	str[5] = NULL;
	fill_env(&menv , env);
	printf("----------------------------------\n");
	b_cd(&menv, str[1]);
	b_cd(&menv, str[0]);
	b_export(&menv, NULL);
	printf("----------------------------------\n");
	b_pwd(menv);
	return (0);
}
