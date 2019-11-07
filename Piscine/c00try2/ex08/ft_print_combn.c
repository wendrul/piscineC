/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 02:51:04 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/01 01:30:14 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		puiss(int x, int n)
{
	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	else
		return (x * puiss(x, n - 1));
}

void	ft_putnbr_zero(int nb, int n)
{
	int ordre;

	if (nb != 0 && nb < puiss(10, n - 1))
		ft_putchar(48);
	ordre = 1;
	while (nb > ordre * 10)
		ordre *= 10;
	while (ordre > 0)
	{
		ft_putchar(48 + nb / ordre);
		nb = nb % ordre;
		ordre /= 10;
	}
}

void	printer(int number, int n, int first)
{
	ft_putnbr_zero(number, n);
	if (!(first == 10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
		ft_putchar('\n');
}

void	ft_print_combn(int n)
{
	int current;
	int prev;
	int cursor;
	int number;
	int is_gud;

	number = puiss(10, n - 2);
	while (number <= puiss(10, n))
	{
		is_gud = 1;
		cursor = 0;
		while (cursor < n)
		{
			current = number % puiss(10, cursor + 1) / puiss(10, cursor);
			prev = number % puiss(10, cursor + 2) / puiss(10, cursor + 1);
			if (current <= prev && prev != 0)
				is_gud = 0;
			cursor++;
		}
		if (is_gud == 1)
			printer(number, n, current);
		number++;
	}
}
