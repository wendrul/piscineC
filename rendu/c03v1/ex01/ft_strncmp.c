/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:32:29 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/05 09:57:05 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	char			*m_s1;
	char			*m_s2;
	unsigned int	i;

	i = 1;
	m_s1 = s1;
	m_s2 = s2;
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
