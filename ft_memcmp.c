/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aacquist <aacquist@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:56:21 by aacquist          #+#    #+#             */
/*   Updated: 2020/11/26 18:51:41 by aacquist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str_1;
	unsigned char *str_2;

	str_1 = (unsigned char *)s1;
	str_2 = (unsigned char *)s2;
	while (n)
	{
		if (*str_1 != *str_2)
			return (*str_1 - *str_2);
		n--;
		str_1++;
		str_2++;
	}
	return (0);
}
