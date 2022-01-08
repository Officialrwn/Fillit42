/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:26:55 by leo               #+#    #+#             */
/*   Updated: 2022/01/09 00:47:33 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static int	check_if_tetrimino_fit(t_piece tetriminos, size_t size, int y, int x)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < 6)
	{
		if (y + tetriminos.content[i] <= size && x + tetriminos.content[i + 1] <= size)
			count++;
		i += 2;
	}
	return (count == 3);
}

int	place_tetrimino(t_piece tetriminos, char **map, int y, int x)
{
	int		i;
	int		count;
	char	c;

	i = 0;
	count = 0;
	c = tetriminos.litera;
	while (i < 6)
	{
		if (map[y + tetriminos.content[i]] \
		[x + tetriminos.content[i + 1]] == '.')
			count++;
		i += 2;
	}
	i = 0;
	if (count == 3)
	{
		map[y][x] = c;
		while (i < 6)
		{
			map[y + tetriminos.content[i]][x + tetriminos.content[i + 1]] = c;
			i += 2;
		}
	}
	return (count == 3);
}

int	solve_tetrimino(t_piece *tetriminos, int count, size_t size, char **map)
{
	int	y;
	int	x;
	int	i;
	int	solve;

	y = 0;
	i = 0;
	while (y < size)
	{
		x = 0;
		solve = 0;
		while (x < size)
		{
			if (map[y][x] == '.' && solve == 0)
			{
				if(check_if_tetrimino_fit(tetriminos[i], size, y, x))
					solve = place_tetrimino(tetriminos[i], map, y, x);
				if (solve)
				{
					i++;
					y = 0;
					break ;
				}
				else
					x++;
			}
			else
				x++;
		}
		if (solve == 0)
			y++;
		if (i == count)
			return (1);
	}
	return (0);
}

/*
**	Segfaults when giving 3 pieces that wont fit but wont segfault when 2
*/