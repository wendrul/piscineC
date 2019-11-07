/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 01:33:25 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/16 09:54:28 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power % 2 == 0)
		return (ft_recursive_power(nb * nb, power / 2));
	else
		return (nb * ft_recursive_power(nb * nb, (power - 1) / 2));
}

int		main(int argc, char **argv)
{
	printf("%s^ %s = %d",argv[0], argv[1] ,ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
	return (0);
}
