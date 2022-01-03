/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:47:40 by marvin            #+#    #+#             */
/*   Updated: 2022/01/03 22:56:36 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	print_arr(int *temp)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i == 4 || i == 8 || i == 12 || i == 16)
			printf("\n");
		printf("%d ", temp[i++]);
	}
	printf("\n\n");
}

void	print_stored_tetrimino(int *numarr)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		printf("%d  %d\n", numarr[i], numarr[i + 1]);
		i += 2;
	}
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
