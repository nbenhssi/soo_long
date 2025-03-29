/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   healper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 15:30:32 by nbenhssi          #+#    #+#             */
/*   Updated: 2025-03-27 15:30:32 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_mapcopy *cp, int x, int y, int *count_c)
{
	if (x < 0 || y < 0 || x >= cp->width || y >= cp->height)
		return ;
	if (cp->mapcopy[y][x] == '1' || cp->mapcopy[y][x] == 'E' ||
		cp->mapcopy[y][x] == 'V')
	{
		if (cp->mapcopy[y][x] == 'E')
			cp->exit = 1;
		return ;
	}
	if (cp->mapcopy[y][x] == 'C')
		(*count_c)++;
	cp->mapcopy[y][x] = 'V';
	flood_fill(cp, x + 1, y, count_c);
	flood_fill(cp, x - 1, y, count_c);
	flood_fill(cp, x, y + 1, count_c);
	flood_fill(cp, x, y - 1, count_c);
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

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	n = n % 10 + '0';
	write(1, &n, 1);
}

void	size_map(char **map, int *height, int *width)
{
	while (map[*height])
		(*height)++;
	*width = 0;
	while (map[0][*width])
		(*width)++;
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
	{
		return (NULL);
	}
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
