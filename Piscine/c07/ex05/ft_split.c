/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:11:29 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/17 17:37:38 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_in(char c, char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

int		word_count(char *str, char *charset)
{
	int n;
	int i;

	n = 0;
	i = -1;
	while (str[++i])
	{
		if (is_in(str[i], charset) == -1)
		{
			while (is_in(str[i], charset) == -1 && str[i])
			{
				i++;
			}
			n++;
			if (!str[i])
				return (n);
		}
	}
	return (n);
}

int		word_length(char *start, char *charset)
{
	int i;

	i = 0;
	while (start[i] && is_in(start[i], charset) == -1)
		i++;
	return (i);
}

char	**init(int *word, int *i, char *s, char *cs)
{
	char **splut;

	*word = -1;
	*i = 0;
	if (!(splut = (char**)malloc(sizeof(char*) * (word_count(s, cs) + 1))))
		return (0);
	return (splut);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		word;
	int		len;
	char	**splut;
	int		j;

	splut = init(&word, &i, str, charset);
	while (++word < word_count(str, charset))
	{
		while (is_in(str[i], charset) != -1)
			i++;
		len = word_length(&str[i], charset);
		if (len >= 0)
		{
			splut[word] = (char*)malloc(sizeof(char) * (len + 1));
			j = -1;
			while (++j < len)
				splut[word][j] = str[i + j];
			splut[word][j] = '\0';
		}
		i += len;
	}
	splut[word_count(str, charset)] = 0;
	return (splut);
}
