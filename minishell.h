/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:50:42 by shbi              #+#    #+#             */
/*   Updated: 2022/11/23 15:26:46 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

// tools
int		ft_strcmp(char *s1, char *s2);
char	*ft_free(char **s);

// envirnment functions
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}			t_env;

t_env	*env_node(char *key, char *value);
void	env_add_end(t_env **lst, t_env *new);
char	*get_key(char *env);
char	*get_value(char *env);
void	fill_env(t_env **menv, char **env);
void	create_if_no_env(t_env **menv);
void	print_env(t_env *menv);
char	*find_value_with_key(t_env *menv, char *key);
t_env	*find_key_node(t_env *menv, char *key);

// builting commands
int		is_option(char *op);
void	b_echo(char **arg, int fd);

void	b_cd(t_env **menv, char *path);
void	cd_home(t_env **menv);
void	new_pwd_and_oldpwd(t_env **menv);
void	add_oldpwd_to_env(t_env **menv, t_env *pwd);
void	add_pwd_to_env(t_env **menv);

int		cmp_key(char *s1, char *s2);
int		env_size(t_env *lst);
char	**env_to_array(t_env *menv);
int		get_index_min(char **array, int i);
char	**sorted_array(char **array);
t_env	*print_sorted_env(t_env *menv);
int		check_export_args(char *arg);
void	b_export(t_env **menv, char **args);

void	b_unset(t_env **menv, char **args);
t_env	*remove_node(t_env *menv, char *key);

void	b_env(t_env *menv);

void	b_pwd(t_env	*menv);

// error case
void	error_msg(const char *error_msg);


#endif