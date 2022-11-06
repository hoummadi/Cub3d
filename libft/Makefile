# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 02:34:15 by hhoummad          #+#    #+#              #
#    Updated: 2021/01/20 18:47:28 by hhoummad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -c

SRCS = ft_atoi.c				\
	   ft_bzero.c				\
	   ft_calloc.c				\
	   ft_isalnum.c				\
	   ft_isalpha.c				\
	   ft_isascii.c				\
	   ft_isdigit.c				\
	   ft_isprint.c				\
	   ft_itoa.c				\
	   ft_memccpy.c				\
	   ft_memchr.c				\
	   ft_memcmp.c				\
	   ft_memcpy.c				\
	   ft_memmove.c				\
	   ft_memset.c				\
	   ft_putchar_fd.c			\
	   ft_putendl_fd.c			\
	   ft_putnbr_fd.c			\
	   ft_putstr_fd.c			\
	   ft_split.c				\
	   ft_strchr.c				\
	   ft_strdup.c				\
	   ft_strjoin.c				\
	   ft_strlcat.c				\
	   ft_strlcpy.c				\
	   ft_strlen.c				\
	   ft_strmapi.c				\
	   ft_strncmp.c				\
	   ft_strnstr.c				\
	   ft_strrchr.c				\
	   ft_strtrim.c				\
	   ft_substr.c				\
	   ft_tolower.c				\
	   ft_toupper.c

SRCSB = ft_lstnew_bonus.c		\
		ft_lstadd_front_bonus.c	\
		ft_lstsize_bonus.c		\
		ft_lstlast_bonus.c		\
		ft_lstadd_back_bonus.c	\
		ft_lstdelone_bonus.c	\
		ft_lstclear_bonus.c		\
		ft_lstiter_bonus.c		\
		ft_lstmap_bonus.c

OBJ = $(SRCS:.c=.o)

OBJB = $(SRCSB:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRCS)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "make libft"

bonus:
	@gcc $(FLAGS) $(SRCSB)
	@ar -rs $(NAME) $(OBJB)
	@ranlib $(NAME)
	@echo "make libft bonus"

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean
	make all
