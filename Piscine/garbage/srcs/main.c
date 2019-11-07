/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 09:47:12 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/21 23:35:56 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parsing.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	int		arg;
	char	buf[4097];
	int		ret;

	if (argc == 1)
	{
		while ((ret = read(0, buf, 4096)))
		{
			buf[ret - 1] = '\0';
			map_parsing(buf);
			write(1, "\n", 1);
		}
	}
	arg = 1;
	while (arg < argc)
	{
		map_parsing(argv[arg]);
		if (arg < argc - 1)
			write(1, "\n", 1);
		arg++;
	}
	return (0);
}
