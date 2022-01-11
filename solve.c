/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:26:55 by leo               #+#    #+#             */
/*   Updated: 2022/01/11 04:49:08 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int	solve(t_piece *tetmin, int count)
{
	int		board_size;
	t_board	board;

	board_size = get_min_board_size(count);
	while (1)
	{
		if (!board_generator(&board, board_size))
			return (0);
		if (try_to_solve(tetmin, &board, count, 0))
		{
			print_board(&board, board_size);
			free_board(&board, board_size);
			return (1);
		}
		free_board(&board, board_size);
		board_size++;
	}
}

int	try_to_solve(t_piece *tetmin, t_board *board, int count, int i)
{
	int	x;
	int	y;
	int	was_inserted;

	y = 0;
	while (y < board->size)
	{
		x = 0;
		while (x < board->size)
		{
			was_inserted = place_tetrimino(&tetmin[i], board, y, x);
			if (was_inserted && i == count - 1)
				return (1);
			else if (was_inserted)
			{
				if (try_to_solve(tetmin, board, count, i + 1))
					return (1);
				else
					remove_tetrimino(&tetmin[i], board, y, x);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	place_tetrimino(t_piece *tetmin, t_board *board, int y, int x)
{
	int		i;
	int		valid_place;

	i = 0;
	valid_place = validate_place(tetmin, board, y, x);
	if (valid_place)
	{
		board->content[y][x] = tetmin->litera;
		while (i < 6)
		{
			board->content[y + tetmin->content[i]] \
			[x + tetmin->content[i + 1]] = tetmin->litera;
			i += 2;
		}
	}
	return (valid_place);
}

int	validate_place(t_piece *tetmin, t_board *board, int y, int x)
{
	int		i;
	int		count;
	int		ytemp;
	int		xtemp;

	i = 0;
	count = 0;
	if (board->content[y][x] != '.')
		return (0);
	while (i < 6)
	{
		ytemp = y + tetmin->content[i];
		xtemp = x + tetmin->content[i + 1];
		if (ytemp < 0 || ytemp >= board->size || \
			xtemp < 0 || xtemp >= board->size)
			return (0);
		if (board->content[ytemp][xtemp] == '.')
			count++;
		i += 2;
	}
	return (count == 3);
}

void	remove_tetrimino(t_piece *tetmin, t_board *board, int y, int x)
{
	int	i;

	i = 0;
	board->content[y][x] = '.';
	while (i < 6)
	{
		board->content[y + tetmin->content[i]] \
		[x + tetmin->content[i + 1]] = '.';
		i += 2;
	}
}
