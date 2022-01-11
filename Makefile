NAME = fillit
SRC = main.c boardgenerator.c get_tetriminos.c solve.c
LIB = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror -I. -I includes
O_FILES = $(SRC:.c=.o)

all: $(NAME)

 $(NAME):
	$(MAKE) -C libft/
	gcc $(FLAGS) -c $(SRC) 
	gcc -o $(NAME) $(O_FILES) $(LIB)
	
clean:
	/bin/rm -f $(O_FILES)
	cd libft && $(MAKE) clean

fclean: clean
	/bin/rm -f $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all