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

static int	ft_check_file_input(char *arr, int fd, char *line)
{
	int	n;
	int	count;
	int check;
	int	i;

	n = 0;
	count = 0;
	check = 0;
	while (n++ < 4) // Read first tetriminos
	{
		ft_get_next_line(fd, &line);
		if (line == NULL || &line[4] != ft_strchr(line, '\0'))
			count = -1;
		i = 0;
		while (i < 4 && count >= 0) // Check tetriminoes has only '.' || '#'
		{
			if (line[i] != '#' && line[i] != '.')
			{
				count = -1;
				break ;
			}
			else
				printf("%c", line[i]); //arr[x][y] = line[i];
			i++;
		}
		printf("$\n"); // line[i] = '\0' (i is now 4);
		ft_strdel(&line);
	}
	if (count == -1)
		return (-1);
	ft_putendl(NULL); // remove
	return (ft_get_next_line(fd, &line));
}

static int ft_check_tetrminos(int *numarr)
{
	
}

static int	count_tetriminos(int fd)
{
	char	*line;
	int		i, y;
	int		x = 0;
	int		check;
	char	arr[26][4];

	i = 1;
	check = 1;
	while (i > 0)
	{
		i = ft_check_file_input(arr[x], fd, line);
		if (i == -1)
			check = -1;
		else if (i == 1)
		{
			x++;
			check++;
		}	
	}
	/*x = 0;
	while (x < 19)
	{
		if (numarr[x][0] != 0)
		{
			ft_foreach(numarr[x], 4, &ft_putnbr);
			ft_putendl(NULL);
		}
		x++;
	}*/
	//printf("final check = %d\n", check);
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
