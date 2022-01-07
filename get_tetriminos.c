/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:46:18 by leo               #+#    #+#             */
/*   Updated: 2022/01/07 19:23:24 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int	read_tetrimino(int fd, t_piece *tetriminos, char c)
{
	int		i;
	int		j;
	int		count;
	char	temp[17];
	char	*line;

	i = 21;
	count = 0;
	while (i > 20)
	{
		i = check_tetrimino_format(fd, temp, line);
		j = validate_tetrimino(temp);
		if (i > 0 && j > 0)
		{
			tetriminos[count].content = (int *)malloc(sizeof(int) * 6);
			if (!tetriminos[count].content)
				return (-1);
			store_tetrmino(temp, tetriminos[count]);
			tetriminos[count].litera = c + count;
			count++;
		}
		if (i == -1 || j == -1)
			return (-1);
	}
	return (count);
}

int	check_tetrimino_format(int fd, char *temp, char *line)
{
	char	buffer[22];
	int		i;
	int		j;
	int		read_ret;

	i = 0;
	j = 0;
	read_ret = read(fd, buffer, 21);
	temp[16] = '\0';
	while (read_ret > 0 && i < 20)
	{
		buffer[read_ret] = '\0';
		if (i % 5 == 4 && buffer[i] != '\n')
			return (-1);
		else if (buffer[i] == '#' || buffer[i] == '.')
			temp[j++] = buffer[i++];
		else
			i++;
	}
	if (read_ret == 0 || (read_ret >= 20 && j != 16))
		return (-1);
	return (read_ret);
}

int	validate_tetrimino(char *temp)
{
	int	i;
	int	block_count;
	int	block_check;

	i = 16;
	block_count = 0;
	block_check = 0;
	while (i--)
	{
		if (temp[i] == '#')
		{
			block_count++;
			if (i > 3 && temp[i - 4] == '#')
				block_check++;
			if (i < 12 && temp[i + 4] == '#')
				block_check++;
			if (i % 4 > 0 && temp[i - 1] == '#')
				block_check++;
			if (i % 4 < 3 && temp[i + 1] == '#')
				block_check++;
		}
	}
	if (block_count != 4 || (block_check != 6 && block_check != 8))
		return (-1);
	return (block_count);
}

void	store_tetrmino(char *temp, t_piece tetriminos)
{
	int	y;
	int	x;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp[i] != '#')
		i++;
	if (temp[i] == '#')
	{
		y = (i - (i % 4)) / 4;
		x = i % 4;
	}
	while (i++ < 16 && j < 6)
	{
		if (temp[i] == '#')
		{
			tetriminos.content[j] = (i - (i % 4)) / 4 - y;
			tetriminos.content[j + 1] = (i % 4) - x;
			j += 2;
		}
	}
}

int	free_tetriminos(t_piece *tetriminos)
{
	int	i;

	i = 26;
	while (i--)
	{
		if (tetriminos[i].content != NULL)
		{
			free(tetriminos[i].content);
			tetriminos[i].content = NULL;
		}
	}
	return (-1);
}
