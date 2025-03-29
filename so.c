/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:31:53 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/29 00:00:23 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_data *m)
{
	if (m->player)
		mlx_destroy_image(m->mlx, m->player);
	if (m->wall)
		mlx_destroy_image(m->mlx, m->wall);
	if (m->collectible)
		mlx_destroy_image(m->mlx, m->collectible);
	if (m->emptyspace)
		mlx_destroy_image(m->mlx, m->emptyspace);
	if (m->exit)
		mlx_destroy_image(m->mlx, m->exit);
}

void	load(t_data *m)
{
	int	w;
	int	h;

	m->player = mlx_xpm_file_to_image(m->mlx, "./images/player.xpm", &w, &h);
	m->collectible = mlx_xpm_file_to_image(m->mlx, "./images/coll.xpm", &w, &h);
	m->exit = mlx_xpm_file_to_image(m->mlx, "./images/exit.xpm", &w, &h);
	m->wall = mlx_xpm_file_to_image(m->mlx, "./images/wall.xpm", &w, &h);
	m->emptyspace = mlx_xpm_file_to_image(m->mlx, "./images/empty.xpm", &w, &h);
	if (!(m->player) || !(m->collectible)
		|| !(m->exit) || !(m->wall) || !(m->emptyspace))
	{
		write(2, "Error\n", 7);
		free_map(m->map);
		free_images(m);
		mlx_destroy_window(m->mlx, m->win);
		mlx_destroy_display(m->mlx);
		free(m->mlx);
		exit(0);
	}
}

static void	render_tile(t_data *m, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(m->mlx, m->win, m->wall, x * SZ, y * SZ);
	else if (tile == 'P')
	{
		m->x_player = x;
		m->y_player = y;
		mlx_put_image_to_window(m->mlx, m->win, m->player, x * SZ, y * SZ);
	}
	else if (tile == 'C')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->collectible, x * SZ, y * SZ);
		m->count_c++;
	}
	else if (tile == 'E')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->exit, x * SZ, y * SZ);
	}
	else if (tile == '0')
		mlx_put_image_to_window(m->mlx, m->win, m->emptyspace, x * SZ, y * SZ);
}

void	render_map(t_data *m)
{
	int	x;
	int	y;

	m->count_c = 0;
	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			render_tile(m, m->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	libix(char **map)
{
	t_data	m;

	m.height = 0;
	m.width = 0;
	m.map = map;
	m.x_player = -1;
	m.y_player = -1;
	size_map(map, &m.height, &m.width);
	m.mlx = mlx_init();
	 if (!m.mlx)
	 {
	 	free_map(map);
	 	write(2, "Error\nmlx_init\n", 16);
	 	exit(1);
	 }
	m.win = mlx_new_window(m.mlx, m.width * 32, m.height * 32, "so_long");
	 if (!m.win)
	 {
	 	free_map(map);
	 	write(2, "Error\nmlx_win\n", 15);
	 	exit(1);
	 }
	load(&m);
	render_map(&m);
	mlx_hook(m.win, 17, 0, close_handler, &m);
	mlx_hook(m.win, 2, (1L << 0), key_hook, &m);
	mlx_loop(m.mlx);
}
