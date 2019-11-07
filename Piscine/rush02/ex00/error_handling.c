/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:12:47 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/20 10:15:46 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		error_message(int error_number)
{
	if (error_number == 0)
		ft_putstr("Error\n");
	if (error_number == 1)
		ft_putstr("Dict Error\n");
	if (error_number == 2)
		ft_putstr("Error (debug only): substraction is negative\n");
	return (0);
}
