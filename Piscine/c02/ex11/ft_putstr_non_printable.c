/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:49:55 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/12 12:55:28 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		is_printable(char c)
{
	return (c < 32 || c >= 127);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_printable(str[i]))
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			print_hex(str[i], 2);
		}
		i++;
	}
}
