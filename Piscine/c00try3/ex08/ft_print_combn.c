/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 02:51:04 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/01 18:07:17 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int		puiss(int x, int n)
{
	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	if (n % 2 == 0)
		return (puiss(x * x, n / 2));
	else
		return (x * puiss(x * x, (n - 1) / 2));
}

void	ft_putnbr_zero(int nb, int n)
{
	int		ordre;
	char	c;

	c = 48;
	if (nb != 0 && nb < puiss(10, n - 1))
		write(1, &c, 1);
	ordre = 1;
	while (nb >= ordre * 10)
		ordre *= 10;
	while (ordre > 0)
	{
		c = 48 + nb / ordre;
		write(1, &c, 1);
		nb = nb % ordre;
		ordre /= 10;
	}
}

int		why_nine_slow(int number, int n)
{
	if (number <= 30000001)
		return (1);
	else
		ft_putnbr_zero(123456789, n);
	return (0);
}

void	printer(int number, int n, int first)
{
	char c;

	ft_putnbr_zero(number, n);
	if (!(first == 10 - n))
	{
		c = ',';
		write(1, &c, 1);
		c = ' ';
		write(1, &c, 1);
	}
}

void	ft_print_combn(int n)
{
	int current;
	int prev;
	int cursor;
	int number;
	int is_gud;

	number = puiss(10, n - 2);
	while (number <= (puiss(10, n - 1) * (11 - n)) && why_nine_slow(number, n))
	{
		is_gud = 1;
		cursor = 0;
		while (cursor < n && is_gud == 1)
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
