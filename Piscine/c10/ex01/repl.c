/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:42:00 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/21 01:55:09 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "head.h"

int		cat_repl()
{
	char	buf[25000];
	int		bytes;
	int old_bytes = 10;

	while ((bytes = read(0, buf, 2500)))
	{
		buf[bytes] = '\0';
		display(1, buf, bytes);
		write(1, "\n", 1);
	}
}
