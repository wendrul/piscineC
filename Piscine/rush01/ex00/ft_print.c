/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:04:02 by gchalas           #+#    #+#             */
/*   Updated: 2019/08/11 15:04:11 by gchalas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_print(int **solution_map, int size)
{
	int x;
	int y;
	int number;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			number = solution_map[x][y] + '0';
			write(1, &number, 1);
			if (x != size - 1)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
