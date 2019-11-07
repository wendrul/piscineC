/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 09:53:03 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/21 23:52:31 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map_parsing.h"
#include "lib_tab.h"
#include "read_file.h"
#include "ft_split.h"
#include "ft_atoi.h"
#include "error.h"
#include "board.h"
#include "logic.h"
#include <unistd.h>
#include <stdio.h>

int		char_is_valid(char c, char *data, char *obstacle, char *filler)
{
	int		len;

	len = ft_strlen(data);
	*filler = data[len - 1];
	*obstacle = data[len - 2];
	return (c == data[len - 3] || c == *obstacle);
}

void	print_board(t_board board)
{
	int i;

	i = 0;
	while (i < board->height)
	{
		ft_putstr(board->board[i]);
		write(1, "\n", 1);
		i++;
	}
}

void	initialize(int *lines, int *i)
{
	*i = -1;
	*lines = 0;
}

int		map_is_valid(char *text, struct s_board *map, char *obs, char *fill)
{
	int		lines;
	int		i;
	int		j;

	initialize(&lines, &i);
	while (text[++i])
		if (text[i] == '\n')
			lines += 1;
	if (!map->board[0] || lines != tab_size(map->board) ||
			lines - 1 != (map->height = ft_atoi(map->board[0])))
		return (0);
	if (!map->board[1] || map->height < 1)
		return (0);
	i = 0;
	map->width = ft_strlen(map->board[1]);
	while (map->board[++i])
	{
		if (ft_strlen(map->board[i]) != map->width || map->width == 0)
			return (0);
		j = -1;
		while (map->board[i][++j])
			if (!char_is_valid(map->board[i][j], map->board[0], obs, fill))
				return (0);
	}
	return (1);
}

int		map_parsing(char *path)
{
	char			*text;
	struct s_board	map;
	char			obstacle;
	char			filler;
	int				i;

	if (!get_file(&text, path))
		return (0);
	if (!(map.board = ft_split(text, "\n")))
		return (0);
	if (!map_is_valid(text, &map, &obstacle, &filler))
		return (map_error());
	free(map.board[0]);
	free(text);
	map.board++;
	fill_biggest_square(&map, obstacle, filler);
	print_board(&map);
	i = 0;
	while (++i < map.height)
		free(map.board[i]);
	free(map.board - 1);
	return (0);
}
