/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:44:39 by shbi              #+#    #+#             */
/*   Updated: 2022/12/24 10:53:46 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*remove_node(t_env *menv, char *key)
{
	t_env	*next;
	t_env	*new_env;

	new_env = NULL;
	while (menv)
	{
		next = menv->next;
		// menv->next = NULL;
		if (cmp_key(menv->key, key) == 0)
		{
			free(menv->value);
			free(menv->key);
			free(menv);
		}
		else
		{
			env_add_end(&new_env, env_node(menv->key, menv->value));
			free(menv);
		}
		menv = next;
	}
	free(key);
	return (new_env);
}

// t_env	*remove_node(t_env *menv, char *key)
// {
// 	t_env	*next;
// 	t_env	*curr;

// 	while (menv)
// 	{
		
// 	}
// }

void	b_unset(t_env **menv, char **args)
{
	int		i;
	t_env	*new_env;

	new_env = *menv;
	if (!args || !*args)
		return ;
	else
	{
		i = 0;
		while (args[i])
		{
			if (find_key_node(new_env, ft_strdup(args[i])))
				new_env = remove_node(new_env, ft_strdup(args[i]));
			i++;
		}
	}
	*menv = new_env;
}
