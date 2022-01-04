/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:35:26 by leo               #+#    #+#             */
/*   Updated: 2022/01/04 21:44:26 by leo              ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_piece tetriminos[5];
	
	test_function(tetriminos[0]);
	
	return (0);
}