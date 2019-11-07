/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 04:43:21 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/16 00:04:09 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (dest[++i])
	{
	}
	while (src[++j])
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}

int		mall_size(int size, char **strs, char *sep)
{
	int length;
	int i;

	i = -1;
	length = 0;
	while (++i < size)
	{
		if (strs[i][0])
			length += ft_strlen(strs[i]) + ft_strlen(sep);
	}
	length -= ft_strlen(sep);
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		length;
	char	*str;

	if (size <= 0)
		return ((char*)malloc(sizeof(char)));
	length = mall_size(size, strs, sep);
	if (!(str = (char*)malloc(sizeof(*str) * length)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (strs[i][0] && i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	str[length] = '\0';
	return (str);
}
