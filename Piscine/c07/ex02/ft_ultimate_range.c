/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 03:36:52 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/15 11:41:06 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	ft_abs(long n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = (int*)malloc(sizeof(min) * ft_abs(max - min));
	if (!(*range))
		return (-1);
	i = -1;
	while (++i < ft_abs(max - min))
	{
		(*range)[i] = i + min;
	}
	return (i);
}
