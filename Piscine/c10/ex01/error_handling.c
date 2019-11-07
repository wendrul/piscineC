/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:34:23 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/20 14:00:09 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		error_not_found(char *path)
{
	ft_putstr(path, 2);
	ft_putstr(": No such file or directory\n", 2);
	return (0);
}

int		error_is_dir(char *path)
{
	ft_putstr(path, 2);
	ft_putstr(": Is a directory\n", 2);
	return (0);
}
