/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:34:23 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/16 14:27:50 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		error_no_args()
{
	ft_putstr("File name missing.\n", 2);
	return (0);
}

int		error_too_many_args()
{
	ft_putstr("Too many arguments.\n", 2);
	return (0);
}

int		error_cant_read()
{
	ft_putstr("Cannot read file.\n", 2);
	return(0);
}
