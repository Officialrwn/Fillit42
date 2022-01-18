/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:26:55 by leo               #+#    #+#             */
/*   Updated: 2022/01/15 18:55:30 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int validy(t_piece *tetmin, t_board *board, int y)
{
	int		i;
	int		ytemp;

	i = 0;
	while (i < 6)
	{
		ytemp = y + tetmin->content[i];
		if (ytemp >= board->size)
			return (0);
		i += 2;
	}
	return (1);
}

int validx(t_piece *tetmin, t_board *board, int x)
{
	int		i;
	int		xtemp;

	i = 0;
	while (i < 6)
	{
		xtemp = x + tetmin->content[i];
		if (xtemp >= board->size)
			return (0);
		i += 2;
	}
	return (1);
}

int	solve(t_piece *tetmin, int count)
{
	size_t	board_size;
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
	int	valid_place;

	y = 0;
	while (validy(&tetmin[i], board, y) && y < board->size)
	{
		x = 0;
		while (x < board->size)
		{
			valid_place = validate_place(&tetmin[i], board, y, x);
			if (valid_place && i == count - 1)
				return (1);
			else if (valid_place)
			{
				if (try_to_solve(tetmin, board, count, i + 1))
					return (1);
				remove_tetrimino(&tetmin[i], board, y, x);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	validate_place(t_piece *tetmin, t_board *board, int y, int x)
{
	int		i;
	int		ytemp;
	int		xtemp;

	i = 0;
	if (board->content[y][x] != '.')
		return (0);
	while (i < 6)
	{
		ytemp = y + tetmin->content[i];
		xtemp = x + tetmin->content[i + 1];
		if (xtemp < 0 || xtemp >= board->size \
			|| board->content[ytemp][xtemp] != '.')
			return (0);
		i += 2;
	}
	return (place_tetrimino(tetmin, board, y, x));
}

int	place_tetrimino(t_piece *tetmin, t_board *board, int y, int x)
{
	int	i;
	int	ytemp;
	int	xtemp;

	i = 0;
	board->content[y][x] = tetmin->litera;
	while (i < 6)
	{
		ytemp = y + tetmin->content[i];
		xtemp = x + tetmin->content[i + 1];
		board->content[ytemp][xtemp] = tetmin->litera;
		i += 2;
	}
	//print_board(board, board->size);
	return (1);
}

void	remove_tetrimino(t_piece *tetmin, t_board *board, int y, int x)
{
	int	i;
	int	ytemp;
	int	xtemp;

	i = 0;
	board->content[y][x] = '.';
	while (i < 6)
	{
		ytemp = y + tetmin->content[i];
		xtemp = x + tetmin->content[i + 1];
		board->content[ytemp][xtemp] = '.';
		i += 2;
	}
}
