/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:03:42 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/05 21:55:52 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_error(char **map)
{
    int i = 0;
    
    if (map)
    {
        while (map[i])
        {
            free(map[i]);
            i++;
        }
        free(map);
    }
    write(2, "Error\n", 6);
    exit(1);
}

void    free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	map = NULL;
	if (argc != 2 || !argv[1])
		return (1);
	check_file_is_valid(argv[1]);
	map = read_map(argv[1]);
	if (!map)
	{
		write(2, "Error\n", 6);
        return (1);
	}
	if (!check_element_doubles(map) || 
        !check_regtangle(map) || 
        !check_walls(map) || !check_file_is_valid(argv[1]))
        {
            ft_error(map);
        }
    libix(map);
    free_map(map);
	return (0);
}
