/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:47:40 by marvin            #+#    #+#             */
/*   Updated: 2022/01/06 21:15:30 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	set_content_to_null(t_piece *tetriminos)
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
	t_piece	tetriminos[26];

	count = 0;
	fd = open(argv[1], O_RDONLY);
	set_content_to_null(tetriminos);
	if (argc != 2 || fd < 0)
		return (0);
	else
	{
		count = read_tetrimino(fd, tetriminos);
		if (count > 0 && count <= 26)
		{
			print_tetrimino_c_yx(tetriminos, count);
			printf("Valid file, tetriminoscount: %d\n", count);
		}
		else
			printf("invalid file\n");
		free_tetriminos(tetriminos);
	}
	return (0);
}
