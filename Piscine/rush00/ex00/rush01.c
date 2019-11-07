/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:17:34 by lpellier          #+#    #+#             */
/*   Updated: 2019/08/03 17:10:38 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_printline(char start, char middle, char end, int x)
{
	int i;

	i = 0;
	ft_putchar(start);
	if (x >= 2)
	{
		while (++i <= (x - 2))
			ft_putchar(middle);
		ft_putchar(end);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int i;

	i = 0;
	if (x <= 0 || y <= 0)
		return ;
	ft_printline('/', '*', 92, x);
	if (y >= 2)
	{
		while (i < (y - 2))
		{
			ft_printline('*', ' ', '*', x);
			i++;
		}
		ft_printline(92, '*', '/', x);
	}
}
