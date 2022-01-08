/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:45:48 by leo               #+#    #+#             */
/*   Updated: 2022/01/08 18:42:18 by leo              ###   ########.fr       */
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

void	print_tetrimino_c_yx(t_piece *tetriminos, int count)
{
	int	i;
	int	j;

	i = 0;
	while (count--)
	{
		j = 0;
		while (j < 6)
		{
			printf("y: %d x: %d\n", tetriminos[i].content[j] \
			, tetriminos[i].content[j + 1]);
			j += 2;
		}
		printf("litera: %c\n\n", tetriminos[i].litera);
		i++;
	}
}
