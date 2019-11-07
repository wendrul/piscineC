/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:38:26 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/12 11:03:25 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = -1;
	if (!to_find[0])
		return (str);
	while (str[++i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
			if (!to_find[++j])
				return (&str[i]);
	}
	return (0);
}

int main()
{
	printf("%s\n", ft_strstr("0abcdef", "c"));
	
	return (0);
}
