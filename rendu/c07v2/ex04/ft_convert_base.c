/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:33:01 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/22 17:37:37 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     check_base(char *base);
int     begin_str(char *str);
int     change(char *str, char *base, int i);
int     ft_atoi_base(char *str, char *base);

char    *rev_char(char *str)
{
	int     i;
	char    tmp;
	int     j;
	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	if (str[i] == '-')
		i++;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

char    *ft_cal_itoa(long int nb, int i, char *itoa, char *base)
{
	int     len;
	len = check_base(base);
	if (nb == 0)
	{
		itoa[0] = base[0];
		i++;
	}
	while (nb > 0)
	{
		itoa[i] = base[nb % len];
		nb = nb / len;
		i++;
	}
	itoa[i] = '\0';
	return (itoa);
}

char    *ft_itoa_base(int nb, char *base)
{
	char        *itoa;
	int         i;
	int         len;
	long int    nbr;
	nbr = nb;
	i = 0;
	len = check_base(base);
	if (!(itoa = (char *)malloc(sizeof(*itoa) * 34)))
		return (0);
	if (nbr < 0)
	{
		itoa[i] = '-';
		nbr = nbr * -1;
		i++;
	}
	itoa = ft_cal_itoa(nbr, i, itoa, base);
	itoa = rev_char(itoa);
	return (itoa);
}

char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int     i;
	int     j;
	int     nb;
	char    *str;
	i = check_base(base_to);
	j = check_base(base_from);
	if (i < 2 || j < 2)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	str = ft_itoa_base(nb, base_to);
	return (str);
}

int	main(int argc, char **argv)
{
	printf("%d -> %d", ft_convert_base(argv[1], argv[2], argv[3]));
	return (0);
}
