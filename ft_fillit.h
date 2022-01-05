/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:47:59 by leo               #+#    #+#             */
/*   Updated: 2022/01/05 23:01:33 by leo              ###   ########.fr       */
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
int		check_tetrimino_format(int fd, int *temp, char *line);
int		validate_tetrimino(int *temp);
int		free_tetriminos(t_piece *tetriminos, int count);
int		store_tetrmino(int *temp, t_piece *tetriminos, char c, int count);
char	**map_generator(int size);
char	**resize_map(int size);
int		free_map(char **map, int i);

void	print_arr(int *temp);
void	print_stored_tetrimino(int *numarr);
void	print_tetrimino_c_yx(t_piece *tetriminos, int count);

#endif
