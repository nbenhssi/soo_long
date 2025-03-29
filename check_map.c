/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:11:57 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/27 03:32:25 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check(t_count *k)
{
	if (k->c_cnt < 1)
		return (write(2, "Error\nAt least one collectible\n", 32), 0);
	if (k->e_cnt != 1)
		return (write(2, "Error\nMust One exit exactly\n", 29), 0);
	if (k->p_cnt != 1)
		return (write(2, "Error\nMust One position exactly\n", 33), 0);
	return (1);
}

int	check_element_doubles(char **map)
{
	t_count	k;

	k.size_x = 0;
	k.c_cnt = 0;
	k.e_cnt = 0;
	k.p_cnt = 0;
	while (map[k.size_x])
	{
		k.size_y = 0;
		while (map[k.size_x][k.size_y])
		{
			if (map[k.size_x][k.size_y] == 'C')
				k.c_cnt++;
			else if (map[k.size_x][k.size_y] == 'E')
				k.e_cnt++;
			else if (map[k.size_x][k.size_y] == 'P')
				k.p_cnt++;
			else if (map[k.size_x][k.size_y] != '0'
				&& map[k.size_x][k.size_y] != '1')
				return (write(1, "Error\nIncorrect caractere\n", 27), 0);
			k.size_y++;
		}
		k.size_x++;
	}
	return (check(&k));
}

int	check_regtangle(char **map)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	while (map[0][j])
		j++;
	size = j;
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != size)
		{
			write(2, "Error\nMap must be rectangular\n", 31);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	(1) && (j = 0, i = 0, x = 0, y = 0);
	while (map[i])
		i++;
	i--;
	while (map[i][j])
		j++;
	j--;
	while (y <= j)
	{
		if (map[0][y] != '1' || map[i][y] != '1')
			return (write(2, "Error\nMap must be enclosed by walls\n", 37), 0);
		y++;
	}
	while (x <= i)
	{
		if (map[x][0] != '1' || map[x][j] != '1')
			return (write(2, "Error\nMap must be enclosed by walls\n", 37), 0);
		x++;
	}
	return (1);
}

int	check_file_is_valid(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (file[i - 1] != '/' && file[i + 1] == 'b' && file[i + 2] == 'e'
				&& file[i + 3] == 'r' && file[i + 4] == '\0')
				return (1);
		}
		i++;
	}
	write(2, "Error\nInvalid map file\n", 24);
	return (0);
}
