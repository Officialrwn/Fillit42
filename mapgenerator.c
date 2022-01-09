/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgenerator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:42:00 by leo               #+#    #+#             */
/*   Updated: 2022/01/09 20:11:26 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

size_t	get_min_board_size(int tet_count)
{
	int	num_hashes;
	int	size;

	size = 1;
	if (tet_count < 4)
		tet_count = 4;
	num_hashes = tet_count * 4;
	while (size * size < num_hashes)
		size++;
	return (size);
}

char	**board_generator(size_t size)
{
	size_t	i;
	char	**board;

	i = 0;
	board = (char **)malloc(sizeof(char *) * size);
	if (!board)
		return (NULL);
	while (i < size)
	{
		board[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (!board[i])
		{
			free_board(board, i);
			return (NULL);
		}
		else
		{
			ft_memset(board[i], '.', size);
			board[i][size] = '\0';
			i++;
		}
	}
	return (board);
}

char	**resize_board(int size)
{
	size = 0;
	return (NULL);
}

void	free_board(char **board, size_t size)
{
	while (size--)
	{
		ft_strdel(&board[size]);
	}
	free(board);
	board = NULL;
}

void	print_board(char **board, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
