/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_itot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:43:55 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/20 10:45:48 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "head.h"

int		get_file_size(int fd)
{
	char	buf[50];
	int		count;

	count = 0;
	while (read(fd, buf, 1))
		count++;
	return (count);
}

int		fill_dict(t_dict *dict, char **tab_dict, t_file *file)
{
	int		i;
	char	**aux_tab;

	i = 0;
	if (!(dict->num = malloc(sizeof(char*) * tab_size(tab_dict))))
		return (0);
	if (!(dict->name = malloc(sizeof(char*) * tab_size(tab_dict))))
		return (0);
	dict->size = tab_size(tab_dict);
	while (tab_dict[i])
	{
		if (!(aux_tab = ft_split(tab_dict[i], " :")))
			return (0);
		if (!(aux_tab[0] = num_is_valid(aux_tab[0])))
			return (!(file->parse_ok = 0));
		dict->num[i] = aux_tab[0];
		if (!(dict->name[i] = ft_strjoin(tab_size(aux_tab + 1), aux_tab + 1, " ")))
			return (0);
		free(aux_tab);
		free(tab_dict[i]);
		i++;
	}
	free(tab_dict);
	return (1);
}

int		parse_dict(char *path, t_dict *dict, t_file *file)
{
	char	*txt_dict;
	char	**tab_dict;

	if (!(txt_dict = (char*)malloc(sizeof(*txt_dict) * (1 + file->size))))
		return (0);
	file->fd = open(path, O_RDONLY);
	read(file->fd, txt_dict, file->size);
	close(file->fd);
	if (!(tab_dict = ft_split(txt_dict, "\n")))
		return (0);
	free(txt_dict);
	return (fill_dict(dict, tab_dict, file));
}

int		parsing_itot(char *path, char *number)
{
	t_file	file;
	t_dict	dict;

	if (!(num_is_valid(number)))
		return (error_message(0));
	if (!(file.fd = open(path, O_RDONLY)))
		return (error_message(0));
	file.size = get_file_size(file.fd);
	close(file.fd);
	file.parse_ok = 1;
	while (!parse_dict(path, &dict, &file))
	{
	}
	if (!file.parse_ok)
		return (error_message(1));
	ft_show_tab(dict);
	test_find_value(dict, number);
	return (0);
}
