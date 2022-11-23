/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:50:40 by shbi              #+#    #+#             */
/*   Updated: 2022/11/23 15:43:43 by shbi             ###   ########.fr       */
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
	str[0] = "saad=merci";
	str[1] = "hbi=olala";
	str[2] = "smart=client";
	str[3] = "smart";
	str[4] = "saad";
	str[5] = NULL;
	fill_env(&menv , env);
	printf("----------------------------------\n");
	b_export(&menv, str);
	b_unset(&menv, str);
	b_export(&menv, NULL);
	printf("----------------------------------\n");
	b_pwd(menv);
	return (0);
}
