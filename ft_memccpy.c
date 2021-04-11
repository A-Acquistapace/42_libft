/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aacquist <aacquist@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:56:21 by aacquist          #+#    #+#             */
/*   Updated: 2020/11/26 15:37:58 by aacquist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *str_d;

	if (!(dst || src))
		return (NULL);
	str_d = dst;
	while (n)
	{
		*str_d = *(char *)src;
		if (*(unsigned char *)src == (unsigned char)c)
			return (str_d + 1);
		n--;
		src++;
		str_d++;
	}
	return (NULL);
}
