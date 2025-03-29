/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:59:47 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/25 20:59:47 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *m)
{
	if (keycode == 65307)
		close_handler(m);
	if (keycode == 65363 || keycode == 100)
		to_right(m);
	if (keycode == 65362 || keycode == 119)
		to_top(m);
	if (keycode == 65361 || keycode == 97)
		to_left(m);
	if (keycode == 65364 || keycode == 115)
		to_bottom(m);
	render_map(m);
	return (0);
}

int	close_handler(t_data *m)
{
	free_map(m->map);
	free_images(m);
	mlx_destroy_window(m->mlx, m->win);
	mlx_destroy_display(m->mlx);
	free(m->mlx);
	exit(0);
}
