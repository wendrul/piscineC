/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 04:12:39 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/03 04:27:44 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	char *m_str;

	m_str = str;
	while (*m_str)
	{
		if (*m_str < 'A' || *m_str > 'Z')
			return (0);
		m_str++;
	}
	return (1);
}
