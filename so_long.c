/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:03:42 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/28 23:58:20 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_fill(char **map, int *x_p, int *y_p, char **mapchecker)
{
	int	x;
	int	y;
	int	cnt_c;

	y = 0;
	cnt_c = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				cnt_c++;
			if (map[y][x] == 'P')
			{
				*x_p = x;
				*y_p = y;
			}
			mapchecker[y][x] = map[y][x];
			x++;
		}
		y++;
	}
	return (cnt_c);
}

void	copy_map(char **map, t_mapcopy *cp)
{
	int	i;
	int	j;

	(1) && (j = 0, i = 0, cp->height = 0, cp->width = 0);
	size_map(map, &cp->height, &cp->width);
	cp->mapcopy = malloc(sizeof(char *) * (cp->height + 1));
	if (!cp->mapcopy)
		return (free(map));
	while (map[j])
	{
		i = 0;
		cp->mapcopy[j] = ft_strdup(map[j]);
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				cp->x_player = i;
				cp->y_player = j;
			}
			if (map[j][i] == 'C')
				cp->cont_c++;
			i++;
		}
		j++;
	}
	cp->mapcopy[j] = NULL;
}

int	main(int argc, char **argv)
{
	char		**map;
	t_mapcopy	cp;
	int			count_c;

	(1) && (cp.exit = 0, cp.cont_c = 0, count_c = 0);
	map = NULL;
	if (argc != 2 || !argv[1][0] )
		return (1);
	map = read_map(argv[1]);
	if (!map)
		return (write(2, "Error\nMap not readed\n", 22), 1);
	if (!check_file_is_valid(argv[1]) || !check_regtangle(map)
		|| !check_element_doubles(map) || !check_walls(map))
		ft_error(map);
	cp.mapcopy = NULL;
	copy_map(map, &cp);
	flood_fill(&cp, cp.x_player, cp.y_player, &count_c);
	free_map(cp.mapcopy);
	if (cp.cont_c != count_c || cp.exit != 1)
	{
		if (cp.exit != 1)
			write(2, "Error go to exit\n", 18);
		else
			write(2, "Error cannot collect all\n", 26);
		ft_error(map);
	}
	return (libix(map), 0);
}


void	copy_map(char **map, t_mapcopy *cp)
{
	int	i;
	int	j;

	(1) && (j = 0, i = 0, cp->height = 0, cp->width = 0);
	size_map(map, &cp->height, &cp->width);
	cp->mapcopy = malloc(sizeof(char *) * (cp->height + 1));
	if (!cp->mapcopy)
		return (free_map(map));
	while (map[j])
	{
		i = 0;
		cp->mapcopy[j] = ft_strdup(map[j]);
		if (cp->mapcopy == NULL)
		{
			free_map(map);
			exit(0);
		}
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				cp->x_player = i;
				cp->y_player = j;
			}
			if (map[j][i] == 'C')
				cp->cont_c++;
			i++;
		}
		j++;
	}
	cp->mapcopy[j] = NULL;
}

int	main(int argc, char **argv)
{
	char		**map;
	t_mapcopy	cp;
	int			count_c;

	(1) && (cp.exit = 0, cp.cont_c = 0, count_c = 0);
	(void )argc;
	map = NULL;
	if (argc != 2 || !argv[1][0])
		return (0);
	map = read_map(argv[1]);
	if (!map)
		return (write(2, "Error\nMap not readed\n", 22), 1);
	if (!check_file_is_valid(argv[1]) || !check_regtangle(map)
		|| !check_element_doubles(map) || !check_walls(map))
		ft_error(map);
	cp.mapcopy = NULL;
	copy_map(map, &cp);
	flood_fill(&cp, cp.x_player, cp.y_player, &count_c);
	free_map(cp.mapcopy);
	if (cp.cont_c != count_c || cp.exit != 1)
	{
		if (cp.exit != 1)
			write(2, "Error\nConnot exit\n", 19);
		else
			write(2, "Error\nConnot\n", 14);
		ft_error(map);
	}
	return (libix(map), 0);
}

