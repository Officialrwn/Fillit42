/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:47:59 by leo               #+#    #+#             */
/*   Updated: 2022/01/06 20:55:20 by leo              ###   ########.fr       */
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

int		read_tetrimino(int fd, t_piece *tetrminos);
int		check_tetrimino_format(int fd, char *temp, char *line);
int		validate_tetrimino(char *temp);
int		free_tetriminos(t_piece *tetriminos);
void	store_tetrmino(char *temp, t_piece tetriminos);
char	**map_generator(int size);
char	**resize_map(int size);
int		free_map(char **map, int i);

void	print_arr(int *temp);
void	print_stored_tetrimino(int *numarr);
void	print_tetrimino_c_yx(t_piece *tetriminos, int count);

#endif
