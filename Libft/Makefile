#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:25:00 by nverdonc          #+#    #+#              #
#    Updated: 2015/01/14 12:50:53 by nverdonc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = ft_memset.c \
		ft_strlen.c \
		ft_strcpy.c \
		ft_strcmp.c \
		ft_putchar.c \
		ft_bzero.c \
		ft_putstr.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strdup.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strclr.c \
		ft_putnbr.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_memalloc.c \
		ft_strlcat.c \
		ft_atoi.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_strpathcat.c \
		ft_putendl.c \
		ft_nbrlen.c \
		ft_lstnew.c \
		ft_strdeld.c

SRCSO = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -c


all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) $(SRCS) -I.
	@ar rc $(NAME) $(SRCSO)
	@ranlib $(NAME)

clean :
	@/bin/rm -f $(SRCSO)
	@/bin/rm -f a.out
	@/bin/rm -f *~

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all

git :
	@git add $(SRCS) Makefile libft.h auteur
	@git commit -m "$(COMMIT)"
	git push $(ORG)

.PHONY : all $(NAME) clean fclean re git