/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkorti-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:33:37 by fkorti-f          #+#    #+#             */
/*   Updated: 2019/08/11 17:37:26 by gchalas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_print(int **solution_map, int size);
void	ft_putstr(char *str);
int		ft_len(char *str);

void	ft_creation_solution_map(int **dataMap, int size)
{
	int count;
	int **solutionMap;

	solutionMap = malloc(sizeof(int *) * size);
	count = 0;
	while (count < size)
	{
		solutionMap[count] = malloc(sizeof(int) * size);
		count++;
	}
	ft_print(dataMap, size);
	ft_print(solutionMap, size);
}

int		ft_filling_data_map(char *str, int **dataMap, int size, int okay)
{
	int count;
	int bigcount;
	int smallcount;

	count = 0;
	bigcount = 0;
	smallcount = 0;
	if (str[0] == ' ')
		okay = 0;
	while (str[count] != '\0')
	{
		if (bigcount >= size)
		{
			bigcount = 0;
			smallcount++;
		}
		if ((str[count] > '0' && str[count] <= '9') &&
				(count == 0 || str[count - 1] == ' '))
		{
			dataMap[bigcount][smallcount] = str[count] - 48;
			count++;
			bigcount++;
		}
		else if (str[count - 1] != ' ' && str[count] == ' ')
			count++;
		else
		{
			okay = 0;
			count++;
		}
	}
	if (str[count - 1] == ' ')
		okay = 0;
	return (okay);
}

void	ft_creation_data_map(char *str, int size)
{
	int **dataMap;
	int count;
	int okay;

	dataMap = malloc(sizeof(int *) * size);
	count = 0;
	while (count < size)
	{
		dataMap[count] = malloc(sizeof(int) * size);
		count++;
	}
	okay = 1;
	okay = ft_filling_data_map(str, dataMap, size, okay);
	if (okay != 0)
		ft_creation_solution_map(dataMap, size);
	else
		ft_putstr("Error\n");
}

int		main(int argc, char **argv)
{
	int size;
	int trou;

	trou = argc - 1;
	size = ft_len(argv[1]);
	if (size >= 3 && size <= 9)
		ft_creation_data_map(argv[1], size);
	else
		ft_putstr("Error\n");
}
