/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 21:47:05 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/21 21:52:57 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_H
# define LOGIC_H

typedef struct	s_rect
{
	struct s_board	*board;
	int				c;
	int				r;
	int				len;
}			*	t_rect;

typedef struct	s_record
{
	int c;
	int r;
}			*	t_record;

void			fill_biggest_square(struct s_board *bo, char obs, char fill);

#endif
