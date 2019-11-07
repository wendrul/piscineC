/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:26:43 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/21 23:35:45 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logic.h"
#include "board.h"

int		is_valid(t_rect rect, int len, char obstacle)
{
	int i;
	int j;

	if (rect->c + len - 1 >= rect->board->width ||
			rect->r + len - 1 >= rect->board->height)
	{
		return (0);
	}
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (rect->board->board[i + rect->r][j + rect->c] == obstacle)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		fill_square(t_board board, struct s_record *rec, int len, char fill)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			board->board[i + rec->r][j + rec->c] = fill;
			j++;
		}
		i++;
	}
	return (1);
}

void	fill_biggest_square(t_board board, char obstacle, char filler)
{
	struct s_rect	cur_rect;
	struct s_record	best_rect;

	cur_rect.board = board;
	cur_rect.r = 0;
	cur_rect.c = 0;
	cur_rect.len = 0;
	best_rect.r = 0;
	best_rect.c = 0;
	while (cur_rect.r < board->height)
	{
		cur_rect.c = 0;
		while (cur_rect.c < board->width)
		{
			while (is_valid(&cur_rect, cur_rect.len + 1, obstacle))
			{
				best_rect.r = cur_rect.r;
				best_rect.c = cur_rect.c;
				cur_rect.len++;
			}
			cur_rect.c++;
		}
		cur_rect.r++;
	}
	fill_square(board, &best_rect, cur_rect.len, filler);
}
