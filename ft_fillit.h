/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:47:59 by leo               #+#    #+#             */
/*   Updated: 2022/01/09 20:09:27 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct s_piece
{
	int		*content;
	int		ylen;
	int		xlen;
	char	litera;
}				t_piece;

int		read_tetrimino(int fd, t_piece *tetrminos, char c);
int		check_tetrimino_format(int fd, char *temp);
int		validate_tetrimino(char *temp);
int		free_tetriminos(t_piece *tetmin);
void	store_tetrmino(char *temp, t_piece *tetmin);
char	**board_generator(size_t size);
char	**resize_board(int size);
void	free_board(char **board, size_t size);
void	print_board(char **board, size_t size);
size_t	get_min_board_size(int tet_count);

int		place_tetrimino(t_piece tetmin, char **board, int y, int x);
int		solve_tetrimino(t_piece *tetmin, int count, int size, char **board);

void	print_arr(int *temp);
void	print_stored_tetrimino(int *numarr);
void	print_tetrimino_c_yx(t_piece *tetmin, int count);

#endif
