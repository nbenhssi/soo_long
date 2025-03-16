/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:03:10 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/03 13:24:16 by nbenhssi         ###   ########.fr       */
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
char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(len + 1);
	if (!s3)
		return (NULL);
	while (s1[i])
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}
