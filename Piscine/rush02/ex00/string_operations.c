/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:57:18 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/20 10:50:02 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_numcmp(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (ft_strlen(s1) - ft_strlen(s2));
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		count_zero(char *s1)
{
	int i;
	int zero;

	i = 0;
	while (s1[i])
	{
		zero = 0;
		while (s1[i] == '0' && s1[i])
		{
			i++;
			zero++;
		}
		i++;
	}
	return (zero);
}

char	*num_is_valid(char *str)
{
	int		i;
	int		j;
	int		flag;

	flag = 0;
	i = 0;
	j = 0;
	while (str[i])
		i++;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (str[i] == '0' && flag == 0 && str[i + 1] != '\0')
			j++;
		else
			flag = 1;
		i++;
	}
	return (str + j);
}

char	nb2_sup_nb1(char *nb1, char *nb2, int size1, int size2)
{
	nb2[size2] = nb1[size1] - nb2[size2] + 48;
	nb1[size1] = '0';
	nb1[size1 - 1] = nb1[size1 - 1] - 1;
	nb1[size1] = nb2[size2] + 10;
	return (nb1[size1]);
}

char	*ft_substract(char *nb1, char *nb2)
{
	int		size1;
	int		size2;

	size1 = ft_strlen(nb1) - 1;
	size2 = ft_strlen(nb2) - 1;
	nb1[size1 + 1] = '\0';
	while (size2 + 1 > 0)
	{
		if (nb1[size1] > nb2[size2])
			nb1[size1] = (nb1[size1] - nb2[size2]) + 48;
		else
		{
			if (nb1[size1] == nb2[size2])
				nb1[size1] = '0';
			else
			{
				if (nb1[size1] < nb2[size2])
					nb1[size1] = nb2_sup_nb1(nb1, nb2, size1, size2);
			}
		}
		size1--;
		size2--;
	}
	return (num_is_valid(nb1));
}
