/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aacquist <aacquist@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:56:21 by aacquist          #+#    #+#             */
/*   Updated: 2020/12/03 21:04:37 by aacquist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cntsign(int a)
{
	int		nb;

	nb = 0;
	if (a == 0)
		return (1);
	if (a < 0)
		nb++;
	while (a != 0)
	{
		nb++;
		a /= 10;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;
	int		nb_sign;

	nb_sign = ft_cntsign(n);
	i = 0;
	if (!(result = malloc((nb_sign + 1) * sizeof(char))))
		return (NULL);
	result[nb_sign] = '\0';
	if (n < 0)
		result[0] = '-';
	if (n == 0)
		result[0] = 48;
	while (n != 0)
	{
		if (n > 0)
			result[nb_sign - 1] = n % 10 + 48;
		else
			result[nb_sign - 1] = -(n % 10) + 48;
		n /= 10;
		nb_sign--;
	}
	return (result);
}
