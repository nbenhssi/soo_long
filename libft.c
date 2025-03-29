/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:03:10 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/27 00:35:42 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_countwords(char *s, char c)
{
	int	i;
	int	count;
	int	k;

	k = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && k != 1)
		{
			k = 1;
			count++;
		}
		else if (s[i] == c)
		{
			k = 0;
		}
		i++;
	}
	return (count);
}

static int	lenword(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	**ft_free_split(char **res, int j)
{
	while (j > 0)
		free (res[--j]);
	free(res);
	return (NULL);
}

static	int	skip_space(char *s, char c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_countwords((char *)s, c) + 1));
	if (!res)
		return (NULL);
	while (j < ft_countwords((char *)s, c))
	{
		k = 0;
		i = skip_space((char *)s, c, i);
		res[j] = (char *)malloc(lenword(s + i, c) + 1);
		if (!(res[j]))
			return (ft_free_split (res, j));
		while (s[i] && s[i] != c)
			res[j][k++] = s[i++];
		res[j++][k] = '\0';
	}
	res[ft_countwords((char *)s, c)] = NULL;
	return (res);
}
