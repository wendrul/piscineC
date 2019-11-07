/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:25:28 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/16 13:59:31 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "head.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (error_no_args());
	if (argc > 2)
		return (error_too_many_args());
	return(display_file(argv[1]));
}
