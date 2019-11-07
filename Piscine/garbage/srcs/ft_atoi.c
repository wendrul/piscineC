/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:21:54 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/21 16:05:59 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char c)
{
	int empty;

	empty = c == '\t' || c == '\n' || c == '\v';
	return (empty || c == '\f' || c == '\r' || c == ' ');
}

int		is_signe(char c, int *sgn)
{
	*sgn *= (c != '-') - (c == '-');
	return (c == '+' || c == '-');
}

int		ft_atoi(const char *str)
{
	unsigned int	nb;
	const char		*m_str;
	int				sgn;

	m_str = str;
	sgn = 1;
	nb = 0;
	while (is_space(*m_str))
		m_str++;
	while (is_signe(*m_str, &sgn))
		m_str++;
	while (*m_str && *m_str <= '9' && *m_str >= '0')
	{
		nb *= 10;
		nb += *m_str - '0';
		m_str++;
	}
	return (sgn * nb);
}
