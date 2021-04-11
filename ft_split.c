/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aacquist <aacquist@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:56:21 by aacquist          #+#    #+#             */
/*   Updated: 2020/12/13 17:36:14 by aacquist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cntwrd(const char *str, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			nb++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (nb);
}

static char		*ft_dup_b(const char *src, int start, int end)
{
	char	*dest;
	int		i;
	int		len;

	len = end - start + 1;
	dest = malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
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

static void		ft_strsclear(char **strs, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
}

char			**ft_fillstrs(char **strs, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	k = -1;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			k++;
			j = i;
			while (s[i] && s[i] != c)
				i++;
			if (!(strs[k] = ft_dup_b(s, j, i - 1)))
			{
				ft_strsclear(strs, k);
				return (NULL);
			}
		}
	}
	strs[ft_cntwrd(s, c)] = NULL;
	return (strs);
}

char			**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	if (!(strs = malloc(sizeof(*strs) * (ft_cntwrd(s, c) + 1))))
		return (NULL);
	if (!(strs = ft_fillstrs(strs, s, c)))
		free(strs);
	return (strs);
}
