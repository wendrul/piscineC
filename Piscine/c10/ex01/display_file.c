/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:31:03 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/21 01:20:09 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "head.h"
#include <stdlib.h>

int		get_file_size(int fd)
{
	char	buf[25000];
	int		bytes;
	int		size;

	size = 0;
	while ((bytes = read(fd, buf, 25000)))
		size += bytes;
	return (size);
}

int		get_file(char *path)
{
	int		fd;
	int		size;
	char	*buf;

	if (((fd = open(path, O_RDONLY)) == -1))
			return (error_not_found(path));
	size = get_file_size(fd);
	close(fd);
	if (((fd = open(path, O_RDONLY)) == -1))
			return (error_not_found(path));
	if (!(buf = (char*)malloc(sizeof(char) * (size + 1))))
			return (0);
	display(fd, buf, size);
	free(buf);
	return (0);
}

void	display(int fd, char *str, int size)
{
	read(fd, str, size);
	write(1, str, size);
	close(fd);
}
