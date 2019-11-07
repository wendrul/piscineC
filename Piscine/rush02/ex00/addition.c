/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elajouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 22:39:21 by elajouan          #+#    #+#             */
/*   Updated: 2019/08/18 23:21:11 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "head.h"

const char	*shortest(const char *a, const char *b)
{
	if (strlen(a) <= strlen(b))
	{
		return (a);
	}
	return (b);
}

const char	*longest(const char *a, const char *b)
{
	if (strlen(a) <= strlen(b))
	{
		return (b);
	}
	return (a);
}

const char	*add_digit(char a, char b, char carry)
{
	static char		out[2] = {'0', '0'};
	int				a_int;
	int				b_int;
	int				carry_int;
	int				sum;

	a_int = (int)(a - 48);
	b_int = (int)(b - 48);
	carry_int = (int)(carry - 48);
	sum = a_int + b_int + carry_int;
	if (sum > 9)
	{
		out[0] = (sum / 10) + 48;
		sum %= 10;
	}
	out[1] = sum + 48;
	return (out);
}

char	*ft_add(const char *a, const char *b)
{
	const char		*s;
	const char		*l;
	unsigned		i;
	char			carry;
	char			*out;
	const char		*digit;

	s = shortest(a, b);
	l = longest(a, b);
	carry = '0';
	out = malloc(strlen(l) + 1);
	i = strlen(l);
	while (i > 0)
	{
		out[i] = ' ';
		i--;
	}
	out[strlen(l)] = '\0';
	i = 0;
	while (i < strlen(l))
	{
		if (i < strlen(s))
		{
			digit = add_digit(s[strlen(s) - i - 1],
					l[strlen(l) - i - 1], carry);
		}
		else
		{
			digit = add_digit('0', l[strlen(l) - i - 1], carry);
		}
		carry = digit[0];
		out[strlen(l) - i] = digit[1];
		i++;
	}
	out[0] = carry;
	num_is_valid((out));
	return (out);
}
