/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:52:32 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/20 13:00:13 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		return (parsing_itot(DEFAULT_DICT, argv[1]));
	if (argc == 3)
		return (parsing_itot(argv[1], argv[2]));
	return (error_message(0));
}
