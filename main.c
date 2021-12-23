/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:47:40 by marvin            #+#    #+#             */
/*   Updated: 2021/12/23 22:47:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

static int	ft_check_file_input(int fd)
{
	char *line;
	int i = 1;
	int count = 0;

	while (i > 0)
	{
		i = ft_get_next_line(fd, &line);
		if (i == 1)
		{
			if (line[4] == '\0')
				count++;
		}
		ft_strdel(&line);
	}
	printf("count = %d\n", count);
	return (1);
}

int main(int argc, char **argv)
{
	int	fd = open(argv[1], O_RDONLY);
	int i = 0;
	if (argc != 2)
		return (0);
	else
	{
		i = ft_check_file_input(fd);
		if (i == 1)
			printf("Valid file");
		else
			printf("invalid file");
	}
	return (0);
}