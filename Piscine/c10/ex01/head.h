/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:35:30 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/20 14:09:02 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef HEAD_H
# define HEAD_H

int		get_file(char *path);
int		error_not_found(char *path);
int		error_is_dir(char *path);
int		error_cant_read();
void	ft_putstr(char *str, int output);
void	ft_putstr(char *str, int output);
void 	display(int fd, char *buf, int size);
int		cat_repl();

#endif
