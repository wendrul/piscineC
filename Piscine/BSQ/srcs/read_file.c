/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:08:22 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/21 23:48:33 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "error.h"
#include <stdio.h>

int		get_file_size(int fd)
{
	char	buf[4097];
	int		size;
	int		bytes;

	size = 0;
	while ((bytes = read(fd, buf, 4096)))
		size += bytes;
	return (size);
}

int		get_file(char **dest, char *path)
{
	int		fd;
	int		size;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (error_cant_open());
	size = get_file_size(fd);
	close(fd);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (error_cant_open());
	if (!(*dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	read(fd, *dest, size + 1);
	(*dest)[size] = '\0';
	return (1);
}
