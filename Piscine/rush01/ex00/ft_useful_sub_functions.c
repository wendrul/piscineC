/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful_sub_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkorti-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 09:31:29 by fkorti-f          #+#    #+#             */
/*   Updated: 2019/08/11 22:28:31 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
}

int	ft_len(char *str)
{
	int count;
	int bigcount;

	bigcount = 0;
	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] >= '0' && str[count] <= '9')
			bigcount++;
		count++;
	}
	return (bigcount / 4);
}

int		ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i]);
	return (i);
}

int		is_in(char c, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (c == str[i])
			return (1);
	return (0);
}
