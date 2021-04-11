/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aacquist <aacquist@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:56:21 by aacquist          #+#    #+#             */
/*   Updated: 2020/11/27 18:45:44 by aacquist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*soluce;

	str = (char *)s;
	soluce = NULL;
	while (*str != '\0')
	{
		if (*str == c)
			soluce = str;
		str++;
	}
	if (*str == c)
		soluce = str;
	if (soluce != NULL)
		return (soluce);
	return (0);
}
