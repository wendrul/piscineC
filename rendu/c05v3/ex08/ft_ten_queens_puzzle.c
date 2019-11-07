/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:13:50 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/16 05:41:48 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int		is_in(char c, char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (1);
	return (0);
}

int		check_col_pos(char *comp, int col, int row)
{
	int is_valid;
	int i;

	is_valid = !is_in(row + '0', comp);
	i = -1;
	while (++i <= col)
	{
		if (row - i == comp[col - i] - '0' || row + i == comp[col - i] - '0')
			is_valid = 0;
	}
	return (is_valid);
}

void	rec_find_sol(char *comp, int col, int *cunt)
{
	int row;

	if (comp[9] != '\0')
	{
		ft_putstr(comp);
		*cunt += 1;
	}
	row = -1;
	while (++row < 10)
	{
		if (check_col_pos(comp, col, row))
		{
			comp[col] = row + '0';
			comp[col + 1] = '\0';
			rec_find_sol(comp, col + 1, cunt);
			comp[col] = '\0';
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		cunt;
	char	comp[11];

	cunt = 0;
	rec_find_sol(comp, 0, &cunt);
	return (cunt);
}
