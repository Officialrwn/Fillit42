/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:47:40 by marvin            #+#    #+#             */
/*   Updated: 2022/01/05 23:57:13 by leo              ###   ########.fr       */
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
			free_tetriminos(tetriminos, count);
		}
		else
			printf("invalid file\n");
	}
	return (0);
}
/* has leaks if file is invalid (count = -1)
** doesnt free the malloced arrays then because cant return 
** count to free tetriminos
** Potentionally rewrite the check_tetrmino_format and skip GNL
** and small change to read_tetrimino.
*/
