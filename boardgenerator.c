/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boardgenerator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:42:00 by leo               #+#    #+#             */
/*   Updated: 2022/01/11 12:04:22 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

size_t	get_min_board_size(int count)
{
	int	num_hashes;
	int	size;

	size = 1;
	num_hashes = count * 4;
	while (size * size < num_hashes)
		size++;
	return (size);
}

int	board_generator(t_board *board, size_t size)
{
	size_t	i;

	i = 0;
	board->content = (char **)malloc(sizeof(char *) * size);
	board->size = size;
	if (!board->content)
		return (0);
	while (i < size)
	{
		board->content[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (!board->content[i])
		{
			free_board(board, i);
			return (0);
		}
		else
		{
			ft_memset(board->content[i], '.', size);
			board->content[i][size] = '\0';
			i++;
		}
	}
	return (1);
}

void	free_board(t_board *board, size_t size)
{
	while (size--)
	{
		ft_strdel(&board->content[size]);
	}
	free(board->content);
	board->content = NULL;
}

void	print_board(t_board *board, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putendl(board->content[i]);
		i++;
	}
}
