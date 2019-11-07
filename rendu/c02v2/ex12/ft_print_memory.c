/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:22:28 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/15 08:12:32 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned long n, int digits)
{
	const char *base = "0123456789abcdef";

	if (n < 16)
	{
		while (--digits > 0)
			write(1, "0", 1);
		write(1, &base[n], 1);
	}
	else
	{
		print_hex(n / 16, digits - 1);
		write(1, &base[n % 16], 1);
	}
}

void	print_line(unsigned int *i, char *addr, unsigned int size, int line_nb)
{
	char	ascii_data[16];
	int		data_len;
	int		n;

	data_len = 16;
	n = *i - 16 * line_nb;
	while (n < 15)
	{
		if (*i < size)
		{
			data_len = n;
			print_hex((unsigned char)(*(addr + *i)), 2);
		}
		else
			write(1, "  ", 2);
		n = *i - 16 * line_nb;
		ascii_data[n] = addr[*i] > 31 && addr[*i] < 126 ? addr[*i] : '.';
		ascii_data[n] = *i < size ? ascii_data[n] : ' ';
		*i = *i + 1;
		if (n % 2 == 1)
			write(1, " ", 1);
	}
	write(1, ascii_data, data_len + 2);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				line_nb;
	unsigned long	addr_val;

	line_nb = 0;
	i = 0;
	while (i < size)
	{
		addr_val = (unsigned long)&addr[i];
		print_hex(addr_val, 15);
		write(1, ": ", 2);
		print_line(&i, addr, size, line_nb);
		line_nb++;
	}
	return (addr);
}
