/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:25:28 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/20 14:09:45 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "head.h"

int		main(int argc, char **argv)
{
	int i;
		
	i = 0;
	if (argc == 1)
	{
		return (cat_repl());
	}
	i = 1;
	while (i < argc)	
	{
		get_file(argv[i]);
		i++;
	}
	return(0);
}
