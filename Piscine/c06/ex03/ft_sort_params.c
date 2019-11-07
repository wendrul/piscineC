/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:48:23 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/17 22:04:44 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	return (*str ? 1 + ft_strlen(str + 1) : 0);
}

void	ft_swap(int *a, int *b)
{
	int chosen_one;

	chosen_one = *a;
	*a = *b;
	*b = chosen_one;
}

int		ft_strcmp(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (ft_strlen(s1) - ft_strlen(s2));
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		ift_strcmp(char *s1, char *s2)
{
	char *m_s1;
	char *m_s2;

	m_s1 = s1;
	m_s2 = s2;
	while (*m_s1 && *m_s2)
	{
		if (*m_s1 != *m_s2)
			return (*m_s1 - *m_s2);
		m_s1++;
		m_s2++;
	}
	return (*m_s1 - *m_s2);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int indices[argc];
	int i;
	int j;

	i = -1;
	while (++i < argc)
		indices[i] = i;
	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_strcmp(argv[indices[i]], argv[indices[j]]) > 0)
				ft_swap(&indices[i], &indices[j]);
		}
	}
	i = 0;
	while (++i < argc)
		ft_putstr(argv[indices[i]]);
	return (0);
}
