/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 02:24:34 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/15 23:32:56 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str);
int		is_space(char c);
int		is_base(char *base);
int		ft_atoi_base(char *nbr, char *base);

long	ft_abs(long x)
{
	return (x < 0 ? -x : x);
}

void	ft_convert_nbr(char *new, long nb, char *base_to, int digit)
{
	long b;

	b = ft_strlen(base_to);
	if (nb < b)
	{
		new[digit] = base_to[nb];
	}
	else
	{
		new[digit] = base_to[nb % b];
		ft_convert_nbr(new, nb / b, base_to, digit - 1);
	}
}

int		how_many_digits(long n, int b)
{
	int		digits;
	long	p;

	digits = 0;
	p = 1;
	while (p <= ft_abs(n))
	{
		p = p * b;
		digits++;
	}
	return (digits);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	digits;
	long			n;
	long			nb;
	char			*new_nbr;

	if (is_base(base_from) && is_base(base_to))
	{
		n = ft_atoi_base(nbr, base_from);
		digits = how_many_digits(n, ft_strlen(base_to));
		if (n < 0)
			digits++;
		new_nbr = (char*)malloc(sizeof(char) * (digits + 1));
		if (n < 0)
		{
			new_nbr[0] = '-';
			nb = -n;
		}
		else
			nb = n;
		new_nbr[digits] = '\0';
		ft_convert_nbr(new_nbr, nb, base_to, digits - 1);
		return (new_nbr);
	}
	return (0);
}
