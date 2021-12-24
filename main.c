/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:47:40 by marvin            #+#    #+#             */
/*   Updated: 2021/12/24 02:52:03 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

static int	ft_check_file_input(int fd, char *line)
{
	int	n;
	int	count;
	int check;
	int	i;

	n = 4;
	count = 0;
	check = 0;
	while (n--)
	{
		ft_get_next_line(fd, &line);
		//put into seperate function returns 1 or 0
		if (line == NULL || &line[4] != ft_strchr(line, '\0'))
			check = -1;
		i = 4;
		while (i-- && check >= 0)
		{
			if (line[i] == '#')
				count++;
			else if (line[i] != '.')
				check = -1;
		}
		//add another check function to check tetriminos pattern
		ft_strdel(&line);
	}
	check = ft_get_next_line(fd, &line);
	if (count != 4)
		check = -1;
	return (check);
}

static int	count_tetriminos(int fd)
{
	char	*line;
	int		i;
	int		check;

	i = 1;
	check = 1;
	while (i > 0)
	{
		i = ft_check_file_input(fd, line);
		if (i == -1)
			check = -1;
		else if (i == 1)
			check++;
	}
	printf("final check = %d\n", check);
	return (check);
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
		i = count_tetriminos(fd);
		if (i > 0 && i <= 26)
			printf("Valid file, tetriminoscount: %d\n", i);
		else
			printf("invalid file");
	}
	return (0);
}
