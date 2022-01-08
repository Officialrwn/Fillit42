/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:47:40 by marvin            #+#    #+#             */
/*   Updated: 2022/01/09 00:44:30 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static void	set_content_to_null(t_piece *tetriminos)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		tetriminos[i].content = NULL;
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int		fd;
	int		count;
	char	**map;
	size_t	size;
	t_piece	tetriminos[26];

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd < 0)
		return (1);
	else
	{
		set_content_to_null(tetriminos);
		count = read_tetrimino(fd, tetriminos, 'A');
		if (count > 0 && count <= 26)
		{
			print_tetrimino_c_yx(tetriminos, count);
			printf("Valid file, tetriminoscount: %d\n\n", count);
			size = get_min_board_size(count);
			map = map_generator(size);
			if (!map)
				return (1);
			if (solve_tetrimino(tetriminos, count, size, map))
				print_map(map, size);
			else
				printf("couldnt fit\n");
			free_map(map, size);
		}
		else
			printf("invalid file\n");
		free_tetriminos(tetriminos);
	}
	return (0);
}
