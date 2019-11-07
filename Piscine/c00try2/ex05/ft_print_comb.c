/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:28:35 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/01 00:54:56 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	to_comma_or_not_to_comma(int end)
{
	if (!end)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
		ft_putchar('\n');
}

void	ft_print_comb(void)
{
	int x;
	int y;
	int z;

	x = -1;
	while (++x <= 7)
	{
		y = x;
		while (++y <= 8)
		{
			z = y;
			while (++z <= 9)
			{
				ft_putchar(48 + x);
				ft_putchar(48 + y);
				ft_putchar(48 + z);
				to_comma_or_not_to_comma(x == 7 && y == 8 && z == 9);
			}
		}
	}
}
