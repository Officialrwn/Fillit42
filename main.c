/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:47:40 by marvin            #+#    #+#             */
/*   Updated: 2022/01/10 10:32:04 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static void	set_content_to_null(t_piece *tetmin)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		tetmin[i].content = NULL;
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int		fd;
	int		count;
	int		is_solved;
	t_piece	tetriminos[26];

	is_solved = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	set_content_to_null(tetriminos);
	count = read_tetrimino(fd, tetriminos, 'A');
	if (count > 0 && count <= 26)
		is_solved = solve(tetriminos, count);
	free_tetriminos(tetriminos);
	if (is_solved == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}
