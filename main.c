/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:47:40 by marvin            #+#    #+#             */
/*   Updated: 2022/01/04 23:20:27 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		count;
	char	c;
	t_piece	tetriminos[26];

	count = 0;
	c = 'A';
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd < 0)
		return (0);
	else
	{
		count = read_tetrimino(fd, tetriminos, c);
		if (count > 0 && count <= 26)
		{
			//Generate Map based on count;
			//Solve function
			//If Map too small, resize map + 1;
			//Solve function
			print_tetrimino_c_yx(tetriminos, count);
			printf("Valid file, tetriminoscount: %d\n", count);
		}
		else
			printf("invalid file");
	}
	return (0);
}
