/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_dictionnaire.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elajouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:58:05 by elajouan          #+#    #+#             */
/*   Updated: 2019/08/18 22:54:15 by elajouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void	ft_swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	int		i;
	char	*temp;

	i = 0;
	src_len = ft_strlen(src);
	temp = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!temp)
		return (NULL);
	while (i < src_len)
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

void	ft_swap_char(char **s1, char **s2)
{
	char *tempo;
	char *tempo2;

	tempo = ft_strdup(*s1);
	tempo2 = ft_strdup(*s2);
	*s1 = tempo2;
	*s2 = tempo;
}

void	ft_sort_dict(t_dico dico)
{
	int i;
	int size;

	i = 0;
	while (i < dict.size)
	{
		if (ft_numcmp(dict.num[i], dict.num[i + 1]) > 0)
		{
			ft_swap_char(&dict.num[i], &dict.num[i + 1]);
			ft_swap_char(&dict.name[i], &dict.name[i + 1]);
			i = -1;
		}
		i++;
	}
}
