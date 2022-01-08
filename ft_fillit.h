/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:47:59 by leo               #+#    #+#             */
/*   Updated: 2022/01/08 19:25:56 by leo              ###   ########.fr       */
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
	char	litera;
}				t_piece;

int		read_tetrimino(int fd, t_piece *tetrminos, char c);
int		check_tetrimino_format(int fd, char *temp, char *line);
int		validate_tetrimino(char *temp);
int		free_tetriminos(t_piece *tetriminos);
void	store_tetrmino(char *temp, t_piece tetriminos);
char	**map_generator(size_t size);
char	**resize_map(int size);
void	free_map(char **map, size_t size);
void	print_map(char **map, size_t size);
size_t	get_min_board_size(int tet_count);

void	print_arr(int *temp);
void	print_stored_tetrimino(int *numarr);
void	print_tetrimino_c_yx(t_piece *tetriminos, int count);

#endif
