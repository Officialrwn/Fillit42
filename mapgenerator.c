/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgenerator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:42:00 by leo               #+#    #+#             */
/*   Updated: 2022/01/08 23:32:17 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

size_t	get_min_board_size(int tet_count)
{
	int		num_hashes;
	int		size;

	size = 1;
	if (tet_count < 4)
		tet_count  = 4;
	num_hashes = tet_count * 4;
	while (size * size < num_hashes)
		size++;
	return (size);
}

char	**map_generator(size_t size)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * size);
	if (!map)
		return (NULL);
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (!map[i])
		{
			free_map(map, i);
			return (NULL);
		}
		else
		{
			ft_memset(map[i], '.', size);
			map[i][size] = '\0';
			i++;
		}
	}
	return (map);
}

char	**resize_map(int size)
{
	return (NULL);
}

void	free_map(char **map, size_t size)
{
	while (size--)
	{
		ft_strdel(&map[size]);
	}
	free(map);
	map = NULL;
}

void	print_map(char **map, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
