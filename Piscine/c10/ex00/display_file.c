/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:31:03 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/20 04:22:55 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "head.h"

void	ft_putstr(char *str, int output)
{
	while(*str)
	{
		write(output, str, 1);
		str++;
	}
}

int		display_file(char *path)
{
	int	fd;
	int				bytes;
	char			buf[50];

	if(((fd = open(path, O_RDONLY)) == -1))
			return (error_cant_read());
	while((bytes = read(fd, buf, 1)))
	{
		if(bytes < 0)
			return(error_cant_read());
		write(1, buf, 1);
	}
	close(fd);
	return (0);
}
