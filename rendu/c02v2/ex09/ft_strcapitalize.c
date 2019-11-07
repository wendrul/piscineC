/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:20:34 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/07 06:30:37 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alphanumeric(char c)
{
	return ((c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z') ||
			(c >= '0' && c <= '9'));
}

int		char_up(char c)
{
	return (c <= 'z' && c >= 'a' ? c - 32 : c);
}

int		char_low(char c)
{
	return (c <= 'Z' && c >= 'A' ? c + 32 : c);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || !is_alphanumeric(str[i - 1]))
			str[i] = char_up(str[i]);
		else
			str[i] = char_low(str[i]);
		i++;
	}
	return (str);
}
