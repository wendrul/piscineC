/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:17:58 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/15 08:17:23 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int len;
	unsigned int n;

	n = -1;
	len = ft_strlen(src);
	if (size > len)
	{
		while (src[++n])
			dest[n] = src[n];
		dest[n] = '\0';
	}
	else
	{
		while (++n < size - 1 && size > 0)
			dest[n] = src[n];
		dest[n] = '\0';
	}
	return (len);
}
