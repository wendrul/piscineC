/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:32:29 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/05 18:57:59 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char		*m_s1;
	unsigned char		*m_s2;
	unsigned int		i;

	i = 1;
	m_s1 = (unsigned char*)s1;
	m_s2 = (unsigned char*)s2;
	while (*m_s1 && *m_s2 && i < n)
	{
		if (*m_s1 != *m_s2)
			return (*m_s1 - *m_s2);
		m_s1++;
		m_s2++;
		i++;
	}
	return (*m_s1 - *m_s2);
}
