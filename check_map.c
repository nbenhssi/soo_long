/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:11:57 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/05 21:54:50 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check(t_count *k)
{
    if (k->e_cnt == 1 && k->c_cnt >= 1 && k->p_cnt == 1)
        return (1);
    else
        return (0);
}
int check_element_doubles(char **map)
{
    t_count   k;

    k.size_x = 0;
    k.size_y = 0;
    k.c_cnt = 0;
    k.e_cnt = 0;
    k.p_cnt = 0;
    while (map[k.size_x])
    {
        k.size_y = 0;
        while(map[k.size_x][k.size_y])
        {
            if (map[k.size_x][k.size_y] == 'C')
				k.c_cnt++;
            else if (map[k.size_x][k.size_y] == 'E')
				k.e_cnt++;
            else if (map[k.size_x][k.size_y] == 'P')
				k.p_cnt++;
			else if (map[k.size_x][k.size_y] != '0' && map[k.size_x][k.size_y] != '1')
				return (0);
            k.size_y++;
        }
        k.size_x++;
    }
    if(!check(&k))
        return (0);
    return (1);
}

int check_regtangle(char  **map)
{
	int	i;
	int	j;
	int	size;
	
	j = 0;
	while(map[0][j])
		j++;
	size = j;
	i = 1;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
			j++;
		if(j != size)
			return (0);
		i++;
	}
	return (1); 
}
int	check_walls(char **map)
{
	int	i;
	int	j;
	
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (map[i])
		i++;
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (0);
		i++;
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
			if (file[i+1] == 'b' && file[i+2] == 'e' && file[i+3] == 'r' && file[i+4] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}