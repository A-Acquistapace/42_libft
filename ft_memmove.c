/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aacquist <aacquist@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:56:21 by aacquist          #+#    #+#             */
/*   Updated: 2020/11/26 17:40:01 by aacquist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *str_d;

	if (!(dst || src))
		return (NULL);
	str_d = dst;
	if (dst >= src)
	{
		str_d += len;
		src += len;
		while (len)
		{
			src--;
			str_d--;
			*str_d = *(char *)src;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
