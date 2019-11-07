/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 00:06:50 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/01 01:16:09 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int ordre;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
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
