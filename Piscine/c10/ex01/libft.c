/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:37:19 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/20 13:41:36 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "head.h"

int		ft_strlen(char *str)
{
	int i;

	i= 0;
	while (str[i])
		i++;
	return(i);
}

void	ft_putstr(char *str, int output)
{
	int		len;

	len = ft_strlen(str);
	write(output, str, len);
}

