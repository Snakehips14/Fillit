# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: behiraux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 17:46:33 by behiraux          #+#    #+#              #
#    Updated: 2019/02/28 21:23:52 by behiraux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEAD = fillit.h

SRC =	main.c \
		ft_read.c \
		ft_verification.c \
		ft_split.c \
		ft_check_pos_hash.c \
		ft_parse.c \
		ft_map.c \
		ft_solver.c

LIBFT = libft/

OBJS = $(SRC:.c=.o)

CC = gcc -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFT) -lft

%.o: %.c $(HEAD)
	$(CC) -c $<

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
