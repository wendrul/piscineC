/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 04:43:21 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/18 23:35:30 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "head.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int dest_length;

	i = 0;
	dest_length = ft_strlen(dest);
	while (src[i])
	{
		dest[i + dest_length] = src[i];
		i++;
	}
	dest[i + dest_length] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		char_count;
	int		i;
	char	*ret;

	if (size == 0)
	{
		ret = malloc(sizeof(char));
		ret[0] = 0;
		return (ret);
	}
	char_count = (size - 1) * ft_strlen(sep);
	i = -1;
	while (++i < size)
		char_count += ft_strlen(strs[i]);
	if (!(ret = malloc(sizeof(char) * (char_count + 1))))
		return (0);
	i = 0;
	ft_strcat(ret, strs[i++]);
	while (i < size)
	{
		ft_strcat(ret, sep);
		ft_strcat(ret, strs[i++]);
	}
	ret[char_count] = 0;
	return (ret);
}
