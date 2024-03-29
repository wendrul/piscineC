/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 03:13:42 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/03 04:52:27 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	char *m_str;

	m_str = str;
	while (*m_str)
	{
		if (*m_str < '0' || *m_str > '9')
			return (0);
		m_str++;
	}
	return (1);
}
