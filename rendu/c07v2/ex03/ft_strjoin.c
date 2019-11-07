/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 04:43:21 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/21 11:03:18 by ede-thom         ###   ########.fr       */
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



#include <stdlib.h>
int     ft_strlen(char *str)
{
	int n;
	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}
int     str_size(int size, char **strs, char *sep)
{
	int     concat_size;
	int     i;
	concat_size = 0;
	i = 0;
	while (i < size)
	{
		concat_size += ft_strlen(strs[i]);
		i++;
	}
	concat_size = concat_size + (ft_strlen(sep) * (size - 1));
	return (concat_size);
}
char    *ft_strjoini2(int size, char **strs, int concat_size, char *sep)
{
	int     i;
	int     j;
	int     p;
	int     k;
	char    *str;
	i = 0;
	p = 0;
	if (!(str = malloc(sizeof(str) * (concat_size + 1))))
		return (0);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[p++] = strs[i][j++];
		k = 0;
		if (i + 1 < size)
		{
			while (sep[k])
				str[p++] = sep[k++];
		}
		i++;
	}
	str[p] = '\0';
	return (str);
}
char    *ft_strjoin(int size, char **strs, char *sep)
{
	int     concat_str;
	char    *str;
	if (size == 0)
	{
		if (!(str = (char*)malloc(sizeof(str))))
			return (0);
		str[0] = 0;
		return (str);
	}
	concat_str = str_size(size, strs, sep);
	if (!(str = ft_strjoini2(size, strs, concat_str, sep)))
		return (0);
	return (str);
}
