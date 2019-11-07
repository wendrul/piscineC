/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:33:22 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/11 23:11:01 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_in(char c, char *str);

int		check_line(int *line, int front, int back, int size)
{
	int i;
	int max;
	int count_visible;
	int line_valid;

	max = line[0];
	count_visible = 0;
	i = -1;
	while (++i < size)
		if (line[i] >= max)
		{
			count_visible++;
			max = line[i];
		}
	max = line[i - 1];
	line_valid = count_visible == front;
	count_visible = 0;
	while (--i >= 0)
		if (line[i] >= max)
		{
			count_visible++;
			max = line[i];
		}
	line_valid = line_valid && (count_visible == back);
	return (line_valid);
}

int		check_row(int **sol_map, int row_num, int **data_map, int size)
{
	int *row;
	int i;
	int row_valid;

	row = malloc(sizeof(*row) * size);
	i = -1;
	while (++i < size)
		row[i] = sol_map[i][row_num];
	row_valid = (check_line(row, data_map[2][i], data_map[3][i], size));
	free(row);
	return (row_valid);
}

int		check_solution(int **sol_map, int **data_map, int size)
{
	int i;
	int valid_sol;

	valid_sol = 1;
	i = -1;
	while (++i < size && valid_sol)
	{
		valid_sol = valid_sol &&
			check_line(sol_map[i], data_map[0][i], data_map[1][i], size);
		valid_sol = valid_sol &&
			check_row(sol_map, i, data_map, size);
	}
	return (valid_sol);
}

int		ft_check_valid_line(int **solution_map, int size)
{
	char track[size + 1];
	int col;
	int row;

	col = 0;
	row = 0;

	while (row < size)
	{
		while (solution_map[col][row] != 0 && col < size)
		{
			if (is_in('0' + solution_map[col][row], track))
			{
				return (0);
			}
			track[col] = '0' + solution_map[col][row];
			track[col + 1] = '\0';
			col++;
		}
		row++;
		track[0] = '\0';
		track[1] = '\0';
		track[2] = '\0';
		track[3] = '\0';
	}
	return(1);
}


