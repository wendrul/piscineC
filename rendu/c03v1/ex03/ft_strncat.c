/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 22:35:50 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/05 09:58:02 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;
	int j;

	j = -1;
	i = -1;
	while (dest[++i])
	{
	}
	while (src[++j] && j < nb)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
