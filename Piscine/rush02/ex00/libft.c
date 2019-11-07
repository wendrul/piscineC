/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:14:34 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/20 10:28:40 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "head.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int len;

	len = ft_strlen(str);
	write(1, str, len);
}

int		index_of(char to_find, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (to_find == str[i])
			return (i);
	}
	return (-1);
}

int		is_space(char c)
{
	int empty;

	empty = c == '\t' || c == '\n' || c == '\v';
	return (empty || c == '\f' || c == '\r' || c == ' ');
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
