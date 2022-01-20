# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 19:40:15 by leo               #+#    #+#              #
#    Updated: 2022/01/20 12:37:17 by leotran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c boardgenerator.c get_tetriminos.c solve.c
LIBFT = libft/
FLAGS = -Wall -Wextra -Werror -I. -I includes
O_FILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)libft.a

clean:
	/bin/rm -f $(O_FILES)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all