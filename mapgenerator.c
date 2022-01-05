/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgenerator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:42:00 by leo               #+#    #+#             */
/*   Updated: 2022/01/05 16:50:36 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

char	**map_generator(int size)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * 5);
	if (!map)
		return (-1);
	while (i < 5)
	{
		map[i] = (char *)malloc(sizeof(char) * 5);
		if (!map[i])
			return (free_map(map, i));
		ft_memset(map[i], '.', 4);
		map[i][4] = '\0';
		i++;
	}
}

char	**resize_map(int size)
{
	return (NULL);
}

int	free_map(char **map, int i)
{
	while (i--)
	{
		ft_strdel(&map[i]);
	}
	ft_strdel(map);
	return (-1);
}
