/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:35:26 by leo               #+#    #+#             */
/*   Updated: 2022/01/05 23:08:54 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_fillit.h"

static void test_function(t_piece tetrimino)
{
	ft_memset(tetrimino.content, 0, sizeof(tetrimino.content));
	for (int i = 0; i < 6; i++)
		printf("t: %d\n", tetrimino.content[i]);
}

int	free_tetriminos(t_piece *tetriminos, int count)
{
	while (count--)
	{
		free(tetriminos[count].content);
		tetriminos[count].content = NULL;
	}
	return (-1);
}

int main(int argc, char **argv)
{
	t_piece tetriminos[5];
	
	//test_function(tetriminos[0]);
	printf("litera: %c\n", tetriminos[0].litera);
	
	//printf("litera: %c content: %d\n", tetriminos[0].litera, tetriminos[0].content[0]);
	//printf("litera: %c content: %d\n", tetriminos[1].litera, tetriminos[1].content[0]);
	//printf("litera: %c content: %d\n", tetriminos[2].litera, tetriminos[2].content[0]);
	//printf("litera: %c content: %d\n", tetriminos[3].litera, tetriminos[3].content[0]);
	//printf("litera: %c content: %d\n", tetriminos[4].litera, tetriminos[4].content[0]);
	
	
	
	return (0);
}