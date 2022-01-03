/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:47:40 by marvin            #+#    #+#             */
/*   Updated: 2022/01/03 16:05:53 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

static void	print_arr(int **temp)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i == 4 || i == 8 || i == 12 || i == 16)
			printf("\n");
		printf("%d ", temp[0][i++]);
	}
	printf("\n\n");
}

static int	check_tetrimino_format(int fd, int **temp, char *line)
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
				temp[0][i++] = 1;
			else if (line[x] != '.' || line[4] != '\0')
				check = 0;
			else
				temp[0][i++] = 0;
			x++;
		}
		ft_strdel(&line);
	}
	return (check);
}

static int	check_valid_tetrimino_piece(int **temp)
{
	int	i;
	int	block_count;
	int	block_check;

	i = 16;
	block_count = 0;
	block_check = 0;
	while (i--)
	{
		if (temp[0][i] == 1)
		{
			block_count++;
			if (i > 3 && temp[0][i - 4] == 1)
				block_check++;
			if (i < 12 && temp[0][i + 4] == 1)
				block_check++;
			if (i % 4 > 0 && temp[0][i - 1] == 1)
				block_check++;
			if (i % 4 < 3 && temp[0][i + 1] == 1)
				block_check++;
		}
	}
	if (block_count != 4 || (block_check != 6 && block_check != 8))
		block_count = 0;
	return (block_count);
}

static int	get_tetrimino(int fd)
{
	int		*temp[4];
	char	*line;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 4)
		temp[i++] = (int *)malloc(sizeof(int) * 4);
	while (i > 0 && count >= 0)
	{
		if (check_tetrimino_format(fd, temp, line) == 1
			&& check_valid_tetrimino_piece(temp) > 0)
		{
			count++;
			i = ft_get_next_line(fd, &line);
			ft_strdel(&line);
			print_arr(temp);
		}
		else
			count = -1;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		return (0);
	else
	{
		i = get_tetrimino(fd);
		if (i > 0 && i <= 26)
			printf("Valid file, tetriminoscount: %d\n", i);
		else
			printf("invalid file");
	}
	return (0);
}
