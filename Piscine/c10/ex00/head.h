/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:35:30 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/16 14:09:41 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int		display_file(char *path);
int		error_too_many_args();
int		error_no_args();
int		error_cant_read();
void	ft_putstr(char *str, int output);

