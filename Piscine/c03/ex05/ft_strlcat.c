/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:41:21 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/09 10:44:41 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = -1;
	while (dest[i])
		i++;
	while (src[++j] && i + j + 1 < size && i < size)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	while (src[j])
		j++;
	if (i < size)
		return (i + j);
	else
		return (size + j);
}

int main()
{
	char mot1[] = "Je fontionne";
	char mot2[] = "Je marche un peu";
	

	printf("%u\n", ft_strlcat(mot1, mot2, 5));

	//printf("%u\n", ft_strlcat(mot1, mot2, 5));
}
