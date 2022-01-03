/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:47:59 by leo               #+#    #+#             */
/*   Updated: 2022/01/03 22:57:12 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h>

int		check_tetrimino_format(int fd, int *temp, char *line);
int		check_valid_tetrimino_piece(int *temp);
int		get_tetrimino(int fd);
void	store_tetrmino(int *temp);

void	print_arr(int *temp);
void	print_stored_tetrimino(int *numarr);

#endif