/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permut_cycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 23:11:22 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/16 02:22:58 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


int		ft_strlen(char *str);
int		is_in(char c, char *str);
int		check_line(int *line, int front, int back, int size);
int		ft_check_valid_line(int **solution_ap, int size);
int		check_solution(int **solution_map, int **data_map, int size);
int		ft_print(int **solution_map, int size);
void	ft_permut_cycle(int **solution_map, int **data_map, char *permutation, char *num_disp, int j, int size, int col);

void	ft_test_permut(int **solution_map, int **data_map, char *permutation, int size, int col)
{
	int		i;
	int		is_valid;
	char	new_perm[size + 1];
	int		done = 0;

	i = -1;
	new_perm[0] = '\0';
	while (permutation[++i])
		solution_map[col][i] = permutation[i] - '0';
	is_valid = check_line(solution_map[col], data_map[0][col], data_map[1][col], size);
	is_valid = is_valid && ft_check_valid_line(solution_map, size);
	printf("caca");
	if (is_valid)
	{
		ft_print(solution_map, size);
		if (1 || solution_map[size - 1][0] != 0)
		{
			if (check_solution(solution_map, data_map, size))
			{
				ft_print(solution_map, size);
				done = 1;
			}
		}
		ft_permut_cycle(solution_map, data_map, new_perm, permutation, 0, size, col + 1);
		if (!done)
			write(1, "Error\n", 6);
		
	}	
}
void	ft_permut_cycle(int **solution_map, int **data_map, char *permutation, char *num_disp, int j, int size, int col)
{
	int i;

	if (ft_strlen(permutation) == size)
	{
		ft_test_permut(solution_map, data_map, permutation, size, col);
	}
	i = -1;
	while(++i < size)
	{
		if (!is_in(num_disp[i], permutation))
		{
			permutation[j] = num_disp[i];
			permutation[j + 1] = '\0';
			ft_permut_cycle(solution_map, data_map, permutation, num_disp, j + 1, size, col);
			permutation[j] = '\0';
		}
	}
}

int		main(int argc, char **argv)
{
	char perm[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

	int count;
	int **solution_map;
	int **data_map;
	int size = 4;

	data_map = malloc(sizeof(int *) * size);
	solution_map = malloc(sizeof(int *) * size);
	count = 0;
	while (count < size)
	{
		solution_map[count] = malloc(sizeof(int) * size);
		data_map[count] = malloc(sizeof(int) * size);
		count++;
	}
	ft_print(data_map, size);
	ft_print(solution_map, size);

	data_map[0][0] = 4;
	data_map[0][1] = 3;
	data_map[0][2] = 2;
	data_map[0][3] = 1;
	data_map[1][0] = 1;
	data_map[1][1] = 2;
	data_map[1][2] = 2;
	data_map[1][3] = 2;
	data_map[2][0] = 4;
	data_map[2][1] = 3;
	data_map[2][2] = 2;
	data_map[2][3] = 1;
	data_map[3][0] = 1;
	data_map[3][1] = 2;
	data_map[3][2] = 2;
	data_map[3][3] = 2;

	ft_permut_cycle(solution_map, data_map, perm, "1234", 0, 4, 0);
	return (0);
}

