/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alezan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:47:59 by alezan            #+#    #+#             */
/*   Updated: 2019/08/20 11:01:05 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "head.h"

char	*test_find_value(t_dict dict, char *nb)
{
	int i;

	i = 0;
	while (i < dict.size)
	{
		if (ft_numcmp(nb, dict.num[i]) == 0)
		{
			ft_putstr(dict.name[i]);
			return (nb);
		}
		i++;
	}
	return (nb);
}

int		is_pow_ten(char *num)
{
	if (num[0] == '1')
		if (count_zero(num) == ft_strlen(num) - 1)
			return (1);
	return (0);
}

int		print_pow_ten(char *number, t_dict dict, int offset)
{
	int		i;
	int		input;
	char	*quotient;

	input = offset;
	i = offset;
	while (ft_numcmp(number, dict.num[i]) > 0)
	{
		ft_substract(number, dict.num[i]);
		quotient = ft_add(quotient, "1");
	}
	int_to_text(quotient, dict, i);
	ft_putstr(dict.name[input]);
	return (i);
}

int		int_to_text(char *number, t_dict dict, int offset)
{
	int	i;

	i = offset - 1;
	if (ft_numcmp(number, dict.num[i]) > 0)
		return (0);
	while (dict.size - i > 0)
	{
		if (ft_numcmp(number, dict.num[i]) == 0)
		{
			ft_putstr(dict.name[i]);
			return (1);
		}
		if (ft_numcmp(number, dict.num[i]) < 0 &&
			count_zero(dict.num[i]) > 0)
		{
			if ((count_zero(dict.num[i]) % 3 >=
						ft_strlen(ft_substract(number, dict.num[i]))))
			{
				ft_putstr(dict.name[i]);
				ft_substract(number, dict.num[i]);
				int_to_text(number, dict, i);
				break ;
			}
			else if (is_pow_ten(dict.num[i]))
			{
				int_to_text(number, dict, print_pow_ten(number, dict, i));
			}
			else
				return (0);
		}
	}
	return (1);
}
