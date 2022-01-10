/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:47:59 by leo               #+#    #+#             */
/*   Updated: 2022/01/10 10:31:57 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_piece
{
	int		*content;
	char	litera;
}				t_piece;

typedef struct s_board
{
	char	**content;
	int		size;
}				t_board;

int		read_tetrimino(int fd, t_piece *tetrminos, char c);
int		check_tetrimino_format(int fd, char *temp);
int		validate_tetrimino(char *temp);
int		free_tetriminos(t_piece *tetmin);
int		board_generator(t_board *board, size_t size);
int		validate_place(t_piece *tetmin, t_board *board, int y, int x);
int		place_tetrimino(t_piece *tetmin, t_board *board, int y, int x);
int		try_to_solve(t_piece *tetmin, t_board *board, int count, int i);
int		solve(t_piece *tetmin, int count);
void	store_tetrmino(char *temp, t_piece *tetmin);
void	free_board(t_board *board, size_t size);
void	print_board(t_board *board, size_t size);
void	remove_tetrimino(t_piece *tetmin, t_board *board, int y, int x);
size_t	get_min_board_size(int count);

#endif
