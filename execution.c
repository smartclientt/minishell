/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:02:47 by shbi              #+#    #+#             */
/*   Updated: 2022/12/21 15:23:32 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Check the input if valide and give theme to the execution
the input is the list of commands
	->	we check the access of every command
	->	we change the value of the arg[0] in our list
	->	we give the command (path command) to the execution (pipes function)
*/

char	*update_cmd_path(t_env *menv, char **cmds)
{
	char	*new_path;

	new_path =  check_cmd_access(menv, cmds[0]);
	return (new_path);
}

void	execution(t_env *menv, char ***cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		cmds[i][0] = update_cmd_path(menv, cmds[i]);
		i++;
	}
	multi_pipes(menv, cmds, 4);
}
