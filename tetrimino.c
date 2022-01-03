/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:35:26 by leo               #+#    #+#             */
/*   Updated: 2022/01/03 15:25:36 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

void	tetminopiece(void)
{
	int numarr[3][2];

	numarr[0][0] = 0;
	numarr[0][1] = 1;
	
	numarr[1][0] = 1;
	numarr[1][1] = -1;
	
	numarr[2][0] = 1;
	numarr[2][1] = 0;
}

static void test_function(int **arr)
{
	arr[0][3] = 1;
}

int main(int argc, char **argv)
{
	int *arr[4];
	for (int i = 0; i < 4; i++)
		arr[i] = (int *)malloc(4 * sizeof(int));

	int i = 3;
	printf("0: %d\n", i % 4);
	i = 7;
	printf("0: %d\n", i % 4);
	i = 11;
	printf("0: %d\n", i % 4);
	i = 15;
	printf("0: %d\n", i % 4);

//	test_function(arr);
	
	ft_foreach(arr[0], 4, &ft_putnbr);
	printf("\n");
	ft_foreach(arr[1], 4, &ft_putnbr);
	printf("\n");
	ft_foreach(arr[2], 4, &ft_putnbr);
	printf("\n");
	ft_foreach(arr[3], 4, &ft_putnbr);
	printf("\n");
	printf("\n");
	/*
	int numarr[3][2];
	numarr[0][0] = 0;
	numarr[0][1] = 1;
	numarr[1][0] = 1;
	numarr[1][1] = -1;
	numarr[2][0] = 1;
	numarr[2][1] = 0;
	
	int i = 0;
	int y = 0, x = 1, check = 3, x2, y2;
	while (check > 0)
	{
		//if (arr[y][x] == 0)
		//{
			arr[y][x] = 1;
			y2 = y + numarr[i][0];
			x2 = x + numarr[i][1];
			printf("y2: %d x2: %d\n", y2, x2);
			if (x2 >= 0 && y2 >= 0 && arr[y2][x2] == 0)
			{
				arr[y2][x2] = 1;
				i++;
				check--;
			}	
			else
				check = -1;
		//}
	}
	if (check == 0)
	{
		printf("\n");
		ft_foreach(arr[0], 4, &ft_putnbr);
		printf("\n");
		ft_foreach(arr[1], 4, &ft_putnbr);
		printf("\n");
		ft_foreach(arr[2], 4, &ft_putnbr);
		printf("\n");
		ft_foreach(arr[3], 4, &ft_putnbr);
		printf("\n");
	}
	else
		printf("Piece did not fit");*/
	return (0);
}