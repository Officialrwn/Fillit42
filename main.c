/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:47:40 by marvin            #+#    #+#             */
/*   Updated: 2021/12/30 04:42:52 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

static void	print_arr(char *temp)
{
	for (int i = 0; i < 17; i++)
	{
		if (i == 4 || i == 8 || i == 12 || i == 16)
			printf("\n");
		printf("%c", temp[i]);
	}
	printf("\n");
}

static int	check_tetrimino_format(int fd, char *temp, char *line)
{
	int		check;
	int		x;
	int		y;
	int		i;

	check = 1;
	y = 0;
	i = 0;
	while (y++ < 4 && check > 0) // Read first tetriminos
	{
		ft_get_next_line(fd, &line);
		x = 0;
		while (x < 4 && check > 0) // Check tetriminoes has only '.' || '#'
		{
			if ((line[x] != '#' && line[x] != '.') || line[4] != '\0')
				check = 0;
			else
				temp[i++] = line[x++];
		}
		ft_strdel(&line);
	}
	temp[16] = '\0';
	return (check);
}

static int	count_blocks(char *temp, int i)
{
	int		count;
	char	c;

	count = 0;
	c = temp[i];
	if (i != 0 && i != 4 && i != 8 && i != 12)
		if (temp[i - 1] == c)
			count++;
	if (i != 3 && i != 7 && i != 11 && i != 15)
		if (temp[i + 1] == c)
			count++;
	if (i != 0 && i != 1 && i != 2 && i != 3)
		if (temp[i - 4] == c)
			count++;
	if (i != 12 && i != 13 && i != 14 && i != 15)
		if (temp[i + 4] == c)
			count++;
	return (count);
}

static int	check_valid_tetrimino_piece(char *temp)
{
	int	check;
	int	count;
	int	i;

	check = 0;
	count = 0;
	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == '#')
		{
			check = check + count_blocks(temp, i);
			count++;
		}
		i++;
	}
	if (count != 4 || (check != 6 && check != 8))
		check = 0;
	return (check);
}

static int	get_tetrimino(int fd) // return t_list *
{
	char	temp[17];
	char	*line;
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (i > 0 && count >= 0)
	{
		if (check_tetrimino_format(fd, temp, line) == 1
			&& check_valid_tetrimino_piece(temp) > 0)
		{
			count++;
			i = ft_get_next_line(fd, &line);
			print_arr(temp); //t_list *head = ft_lstnew(temp, 17);
		}
		else
			count = -1;
	}
	return (count); // return t_list *
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
