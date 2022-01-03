/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetchpieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:46:18 by leo               #+#    #+#             */
/*   Updated: 2022/01/03 23:05:24 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int	get_tetrimino(int fd)
{
	int		temp[16];
	int		i;
	int		count;
	char	*line;

	i = 1;
	count = 0;
	while (i > 0 && count >= 0)
	{
		if (check_tetrimino_format(fd, temp, line) == 1
			&& check_valid_tetrimino_piece(temp) > 0)
		{
			count++;
			i = ft_get_next_line(fd, &line);
			ft_strdel(&line);
			print_arr(temp);
			store_tetrmino(temp);
		}
		else
			count = -1;
	}
	return (count);
}

int	check_tetrimino_format(int fd, int *temp, char *line)
{
	int		check;
	int		x;
	int		y;
	int		i;

	check = 1;
	y = 0;
	i = 0;
	while (y++ < 4 && check > 0)
	{
		ft_get_next_line(fd, &line);
		x = 0;
		while (x < 4 && check > 0)
		{
			if (line[x] == '#')
				temp[i++] = 1;
			else if (line[x] != '.' || line[4] != '\0')
				check = 0;
			else
				temp[i++] = 0;
			x++;
		}
		ft_strdel(&line);
	}
	return (check);
}

int	check_valid_tetrimino_piece(int *temp)
{
	int	i;
	int	block_count;
	int	block_check;

	i = 16;
	block_count = 0;
	block_check = 0;
	while (i--)
	{
		if (temp[i] == 1)
		{
			block_count++;
			if (i > 3 && temp[i - 4] == 1)
				block_check++;
			if (i < 12 && temp[i + 4] == 1)
				block_check++;
			if (i % 4 > 0 && temp[i - 1] == 1)
				block_check++;
			if (i % 4 < 3 && temp[i + 1] == 1)
				block_check++;
		}
	}
	if (block_count != 4 || (block_check != 6 && block_check != 8))
		block_count = 0;
	return (block_count);
}

/*
** store_tetrmino should return a malloced int *arr
** instead of the stack int arr[6] and replace print_stored_arr
** with return int *arr;
*/

void	store_tetrmino(int *temp)
{
	int	arr[6];
	int	y;
	int	x;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp[i] != 1)
		i++;
	if (temp[i] == 1)
	{
		y = (i - (i % 4)) / 4;
		x = i % 4;
	}
	while (i++ < 16)
	{
		if (temp[i] == 1)
		{
			arr[j] = (i - (i % 4)) / 4 - y;
			arr[j + 1] = (i % 4) - x;
			j += 2;
		}
	}
	print_stored_tetrimino(arr);
}
