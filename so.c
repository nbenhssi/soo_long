/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:31:53 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/07 18:06:11 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void size_map(char **map, int *height, int *width)
{
    while (map[*height]) 
        (*height)++;
    *width = 0;
    while (map[0][*width])
        (*width)++;
}

int	close_handler(t_data *m)
{
	mlx_destroy_window(m->mlx, m->win);
    exit(0);
	return (0);
}

void    load(t_data *m)
{
	int width = sz;
	int height = sz;

    *(m->player) = mlx_xpm_file_to_image(m->mlx, "./images/player.xpm", &width, &height);
	*(m->collectible) = mlx_xpm_file_to_image(m->mlx, "./images/collectible.xpm", &width, &height);
	*(m->exit) = mlx_xpm_file_to_image(m->mlx, "./images/exit.xpm", &width, &height);
	*(m->wall) = mlx_xpm_file_to_image(m->mlx, "./images/wall.xpm", &width, &height);
    *(m->emptyspace) = mlx_xpm_file_to_image(m->mlx, "./images/emptyspace.xpm", &width, &height);
}
 
void render_map(t_data *m)
{
    int x, y;
    m->count_c = 0;

    y = 0;
    while (m->map[y])
    {
        x = 0;
        while (m->map[y][x])
        {
            if (m->map[y][x] == '1')
                mlx_put_image_to_window(m->mlx, m->win, *(m->wall), x * sz, y * sz);
            else if (m->map[y][x] == 'P')
            {
                m->x_player = x;
                m->y_player = y;
                mlx_put_image_to_window(m->mlx, m->win, *(m->emptyspace), x * sz, y * sz);
                mlx_put_image_to_window(m->mlx, m->win, *(m->player), x * sz, y * sz);
            }
            else if (m->map[y][x] == 'C')
            {
                mlx_put_image_to_window(m->mlx, m->win, *(m->emptyspace), x * sz, y * sz);
                mlx_put_image_to_window(m->mlx, m->win, *(m->collectible), x * sz, y * sz);
                m->count_c++;
            }
            else if (m->map[y][x] == 'E')
            {
                mlx_put_image_to_window(m->mlx, m->win, *(m->emptyspace), x * sz, y * sz);
                mlx_put_image_to_window(m->mlx, m->win, *(m->exit), x * sz, y * sz);
            }
            else if (m->map[y][x] == '0')
                mlx_put_image_to_window(m->mlx, m->win, *(m->emptyspace), x * sz, y * sz);
            x++;
        }
        y++;
    }
}

int key_hook(int keycode, t_data *m)
{
    if (keycode == 65363)
            to_right(&m);
    if (keycode == 65362)
        to_top(&m);
    if (keycode == 65361)
        to_left(&m);
    if (keycode == 65364)
        to_bottom(&m);
}

void libix(char **map)
{
    t_data  m;           
    t_image img;

    m.height = 0;
    m.width = 0;
    m.map = map;
    m.x_player= -1;
    m.y_player= -1;
    size_map(map, &m.height, &m.width);
    m.mlx = mlx_init();
    m.win = mlx_new_window(m.mlx, m.width * 32, m.height * 32, "so_long");

    m.player = malloc(sizeof(void *));
    m.collectible = malloc(sizeof(void *));
    m.exit = malloc(sizeof(void *));
    m.wall = malloc(sizeof(void *));
    m.emptyspace = malloc(sizeof(void *));
    load(&m);
    m.img.img = mlx_new_image(m.mlx, sz, sz);
    render_map(&m);
    mlx_hook(m.win, 2, (1L << 0), key_hook, &m);
    mlx_hook(m.win, 17, 0, close_handler, &m);
    mlx_loop(m.mlx);
}
