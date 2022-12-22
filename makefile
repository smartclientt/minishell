# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 01:50:38 by shbi              #+#    #+#              #
#    Updated: 2022/12/21 09:41:33 by shbi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
SRCS		=	minishell.c														\
				env_tools.c env_tools_.c tools.c								\
				b_echo.c b_cd.c b_env.c	b_pwd.c b_export.c b_unset.c			\
				error_case.c pipes.c check_cmd.c execution.c
				
OBJS		=	$(SRCS:.c=.o)
HEADR		=	minishell.h
LIBFT		=	./libft/libft.a
PATH_LIBFT	=	./libft
CC			=	cc
FLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

all			:	$(NAME)
				$(RM) $(OBJS)
$(LIBFT)	:
				@make -C $(PATH_LIBFT)
$(NAME)		:	$(OBJS) $(LIBFT)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)
%.o			:	%.c $(HEADR)
				$(CC) $(FLAGS) -c $< -o $@
clean		:
				$(RM) $(OBJS)
				@make clean -C $(PATH_LIBFT)
fclean		:	clean
				$(RM) $(NAME)
				@make fclean -C $(PATH_LIBFT)
re			:	fclean all
				