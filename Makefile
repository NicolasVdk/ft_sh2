#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/12 20:54:52 by nverdonc          #+#    #+#              #
#    Updated: 2015/01/19 15:00:40 by nverdonc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= ft_minishell2
SRC			= ft_sh1.c \
				ft_error.c \
				ft_entry.c \
				ft_command.c \
				ft_second.c \
				ft_verif.c \
				get_next_line.c
OBJ			= $(SRC:.c=.o)
CC			= /usr/bin/gcc
CFLAGS		= -Wall -Wextra -Werror
CDEBUG		= -Wall -Wextra -Werror -ansi -pedantic -g
RM			= /bin/rm -f
ECHO			= /bin/echo -e

$(NAME)	:		$(OBJ)
				@Make -C Libft/ re
				@$(CC) $(CFLAGS) -L Libft -lft -o $(NAME) $(OBJ)
				@$(ECHO) '> Compiled'

clean	:
				-@$(RM) $(OBJ)
				-@$(RM) *~
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
				-@$(RM) $(NAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

.PHONY	:		all clean re

debug	:		$(OBJ)
				@$(CC) $(INC) $(CDEBUG) -o $(NAME) $(OBJ)
				@$(ECHO) '> Mode Debug: done'

.c.o	:
				$(CC) $(CFLAGS) -o $@ -c $<
