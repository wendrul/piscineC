/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:42:32 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/16 06:11:23 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

int		*ft_range(int min, int max)
{
	int *rng;
	int i;

	if (min >= max)
		return (NULL);
	if (!(rng = (int*)malloc(sizeof(min) * ft_abs(max - min))))
		return (NULL);
	i = - 1;
	while (++i < max - min)
		rng[i] = min + i;
	return (rng);
}
