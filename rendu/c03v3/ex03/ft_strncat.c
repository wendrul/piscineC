/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 22:35:50 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/07 19:33:16 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;

	j = -1;
	i = -1;
	while (dest[++i])
	{
	}
	while (src[++j] && j < nb)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}

int main()
{
	char src[] = " - append me bitch!";
	char dest[] = "slam that string into me";
	unsigned int n = 40;
	char srcB[] = " - append me bitch!";
	char destB[] = "slam that string into me";

	printf("src before: %s, dest before: %s\n", src, dest);
	printf("size: %d, mine returned: %s\n", n, ft_strncat(dest, src, n));
	printf("src after : %s, dest after : %s\n\n", src, dest);

	printf("src before: %s, dest before: %s\n", srcB, destB);
	printf("size: %d, they returned: %s\n", n, strncat(destB, srcB, n));
	printf("src after : %s, dest after : %s\n\n", srcB, destB);
}
