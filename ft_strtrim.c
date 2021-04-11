/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aacquist <aacquist@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:56:21 by aacquist          #+#    #+#             */
/*   Updated: 2020/12/13 17:39:05 by aacquist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_isin(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char		*ft_dup(const char *src, int start, int end)
{
	char	*dest;
	int		i;
	int		len;

	len = end - start + 1;
	if (!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_strtrim(char const *str, char const *set)
{
	size_t	start;
	size_t	end;

	if (!str)
		return (NULL);
	start = 0;
	while (ft_isin(str[start], set))
		start++;
	if (start == ft_strlen(str))
		return (ft_strdup(""));
	end = ft_strlen(str) - 1;
	while (ft_isin(str[end], set))
		end--;
	return (ft_dup(str, start, end));
}
