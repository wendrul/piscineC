/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 04:28:01 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/07 23:27:33 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		is_space(char c)
{
	int empty;

	empty = c == '\t' || c == '\n' || c == '\v';
	return (empty || c == '\f' || c == '\r' || c == ' ');
}

int		what_char(char c, char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

int		is_base(char *base)
{
	int i;
	int j;

	i = -1;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[++i])
	{
		if (is_space(base[i]) || base[i] == '-' || base[i] == '+')
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

int		ft_atoi_base(char *nbr, char *base)
{
	int i;
	int n;
	int sgn;

	i = 0;
	n = 0;
	sgn = 1;
	if (is_base(base))
	{
		while (is_space(nbr[i]))
			i++;
		while (nbr[i] == '-' || nbr[i] == '+')
		{
			sgn *= -(nbr[i] == '-') + (nbr[i] == '+');
			i++;
		}
		while (nbr[i] && what_char(nbr[i], base) != -1)
		{
			n *= ft_strlen(base);
			n += what_char(nbr[i], base);
			i++;
		}
		return (sgn * n);
	}
	return (0);
}
