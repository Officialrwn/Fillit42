/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:35:26 by leo               #+#    #+#             */
/*   Updated: 2022/01/03 22:25:55 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

static void test_function(int **arr)
{
	arr[0][3] = 1;
}

int main(int argc, char **argv)
{
	for (int i = 0; i < 16; i++)
		printf("i: %d y: %d x: %d\n", i, (i - (i % 4)) / 4, i % 4);
	// y: (i - (i % 4)) / 4;
	// x: i % 4;
	
	return (0);
}