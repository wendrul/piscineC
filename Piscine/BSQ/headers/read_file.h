/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:33:26 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/21 11:34:51 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

int		get_file_size(int fd);
int		get_file(char **dest, char *path);

#endif
