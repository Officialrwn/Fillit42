/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:26:55 by leo               #+#    #+#             */
/*   Updated: 2022/01/09 20:04:30 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

//void	remove_tetrimino(t_piece )

int	place_tetrimino(t_piece tetmin, char **board, int y, int x)
{
	int		i;
	int		count;
	char	c;

	i = 0;
	count = 0;
	c = tetmin.litera;
	while (i < 6)
	{
		if (board[y + tetmin.content[i]][x + tetmin.content[i + 1]] == '.')
			count++;
		i += 2;
	}
	i = 0;
	if (count == 3)
	{
		board[y][x] = c;
		while (i < 6)
		{
			board[y + tetmin.content[i]][x + tetmin.content[i + 1]] = c;
			i += 2;
		}
	}
	return (count == 3);
}

int	solve_tetrimino(t_piece *tetmin, int count, int size, char **board)
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
			if (board[y][x] == '.' && solve == 0)
			{
				if (tetmin[i].ylen + y < size && tetmin[i].xlen + x < size)
					solve = place_tetrimino(tetmin[i], board, y, x);
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