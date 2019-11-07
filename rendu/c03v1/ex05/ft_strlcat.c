/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:41:21 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/05 08:23:18 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = -1;
	while (dest[i])
		i++;
	while (src[++j] && i + j + 1 < size)
		dest[i + j] = src[j];
	if (!src[j] && i + j + 1 < size)
		dest[i + j] = '\0';
	while (src[j])
		j++;
	if (i < size)
		return (i + j);
	else
		return (size + j);
}
