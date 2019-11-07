/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:48:03 by ede-thom          #+#    #+#             */
/*   Updated: 2019/07/31 21:15:37 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int x;
	int y;

	x = -1;
	while (++x <= 98)
	{
		y = x;
		while (++y <= 99)
		{
			ft_putchar(48 + x / 10);
			ft_putchar(48 + x % 10);
			ft_putchar(' ');
			ft_putchar(48 + y / 10);
			ft_putchar(48 + y % 10);
			if (!(x == 98 && y == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			else
				ft_putchar('\n');
		}
	}
}
