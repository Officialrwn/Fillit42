/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:46:18 by leo               #+#    #+#             */
/*   Updated: 2022/01/05 23:38:31 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int	read_tetrimino(int fd, t_piece *tetriminos, char c)
{
	int		temp[16];
	int		i;
	int		count;
	char	*line;

	i = 1;
	count = 0;
	while (i > 0 && count >= 0)
	{
		if (check_tetrimino_format(fd, temp, line) > 0
			&& validate_tetrimino(temp) > 0)
		{
			tetriminos[count].content = (int *)malloc(sizeof(int) * 6);
			if (!tetriminos[count].content)
				return (free_tetriminos(tetriminos, count));
			count = store_tetrmino(temp, tetriminos, c, count);
			i = ft_get_next_line(fd, &line);
			printf("i: %d line: %s\n", i, line);
			ft_strdel(&line);
		}
		else
			count = -1;
	}
	return (count);
}

int	check_tetrimino_format(int fd, int *temp, char *line)
{
	int	x;
	int	y;
	int	i;

	y = 4;
	i = 0;
	while (y-- && i >= 0)
	{
		ft_get_next_line(fd, &line);
		x = 0;
		while (x < 4 && i >= 0 && line != NULL)
		{
			if (line[x] == '#')
				temp[i++] = 1;
			else if (line[x] != '.' || line[4] != '\0')
				i = -1;
			else
				temp[i++] = 0;
			x++;
		}
		ft_strdel(&line);
	}
	return (i);
}

int	validate_tetrimino(int *temp)
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

int	store_tetrmino(int *temp, t_piece *tetriminos, char c, int count)
{
	int	y;
	int	x;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tetriminos[count].litera = c + count;
	while (temp[i] != 1)
		i++;
	if (temp[i] == 1)
	{
		y = (i - (i % 4)) / 4;
		x = i % 4;
	}
	while (i++ < 16 && j < 6)
	{
		if (temp[i] == 1)
		{
			tetriminos[count].content[j] = (i - (i % 4)) / 4 - y;
			tetriminos[count].content[j + 1] = (i % 4) - x;
			j += 2;
		}
	}
	return (count + 1);
}

int	free_tetriminos(t_piece *tetriminos, int count)
{
	while (count--)
	{
		free(tetriminos[count].content);
		tetriminos[count].content = NULL;
	}
	return (-1);
}
