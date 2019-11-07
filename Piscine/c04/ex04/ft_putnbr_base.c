/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:18:50 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/07 22:18:16 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_bad(char c)
{
	return (c == '+' || c == '-' ||
			c == '\f' || c == '\t' ||
			c == '\n' || c == '\r' ||
			c == '\v' || c == ' ');
}

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

void	print_char(unsigned int nbr, unsigned int b, char *base)
{
	if (nbr < b)
	{
		write(1, &base[nbr], 1);
	}
	else
	{
		print_char(nbr / b, b, base);
		write(1, &base[nbr % b], 1);
	}
}

int		is_base(char *base)
{
	int i;
	int j;

	i = -1;
	j = -1;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[++i])
	{
		if (is_bad(base[i]))
		{
			return (0);
		}
		j = -1;
		while (base[++j])
		{
			if (i != j && base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int b;
	unsigned int nb;

	if (is_base(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nb = -nbr;
		}
		else
			nb = nbr;
		b = ft_strlen(base);
		print_char(nb, b, base);
	}
}
