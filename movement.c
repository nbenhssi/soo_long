/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:12:24 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/26 23:57:06 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	g_moves;

void	write_moves(void)
{
	write(1, "Moves :", 7);
	g_moves = g_moves + 1;
	ft_putnbr(g_moves);
	write(1, "\n", 1);
}

void	to_right(t_data *m)
{
	if (m->map[m->y_player][m->x_player + 1] == '0')
	{
		m->map[m->y_player][m->x_player] = '0';
		m->x_player = m->x_player + 1;
		m->map[m->y_player][m->x_player] = 'P';
		write_moves();
	}
	else if (m->map[m->y_player][m->x_player + 1] == 'C')
	{
		m->map[m->y_player][m->x_player] = '0';
		m->x_player = m->x_player + 1;
		m->map[m->y_player][m->x_player] = 'P';
		m->count_c--;
		write_moves();
	}
	else if (m->map[m->y_player][m->x_player + 1] == 'E')
	{
		if (m->count_c == 0)
		{
			m->map[m->y_player][m->x_player] = '0';
			write_moves();
			write(1, "GOOOOOOOD GAME\n", 15);
			close_handler(m);
		}
	}
}

void	to_top(t_data *m)
{
	if (m->map[m->y_player - 1][m->x_player] == '0')
	{
		m->map[m->y_player][m->x_player] = '0';
		m->y_player = m->y_player - 1;
		m->map[m->y_player][m->x_player] = 'P';
		write_moves();
	}
	else if (m->map[m->y_player - 1][m->x_player] == 'C')
	{
		m->map[m->y_player][m->x_player] = '0';
		m->y_player = m->y_player - 1;
		m->map[m->y_player][m->x_player] = 'P';
		m->count_c--;
		write_moves();
	}
	else if (m->map[m->y_player - 1][m->x_player] == 'E')
	{
		if (m->count_c == 0)
		{
			m->map[m->y_player][m->x_player] = '0';
			write_moves();
			write(1, "GOOOOOOOD GAME\n", 15);
			close_handler(m);
		}
	}
}

void	to_left(t_data *m)
{
	if (m->map[m->y_player][m->x_player - 1] == '0')
	{
		m->map[m->y_player][m->x_player] = '0';
		m->x_player = m->x_player - 1;
		m->map[m->y_player][m->x_player] = 'P';
		write_moves();
	}
	else if (m->map[m->y_player][m->x_player - 1] == 'C')
	{
		m->map[m->y_player][m->x_player] = '0';
		m->x_player = m->x_player - 1;
		m->map[m->y_player][m->x_player] = 'P';
		m->count_c--;
		write_moves();
	}
	else if (m->map[m->y_player][m->x_player - 1] == 'E')
	{
		if (m->count_c == 0)
		{
			m->map[m->y_player][m->x_player] = '0';
			write_moves();
			write(1, "GOOOOOOOD GAME\n", 15);
			close_handler(m);
		}
	}
}

void	to_bottom(t_data *m)
{
	if (m->map[m->y_player + 1][m->x_player] == '0')
	{
		m->map[m->y_player][m->x_player] = '0';
		m->y_player = m->y_player + 1;
		m->map[m->y_player][m->x_player] = 'P';
		write_moves();
	}
	else if (m->map[m->y_player + 1][m->x_player] == 'C')
	{
		m->map[m->y_player][m->x_player] = '0';
		m->y_player = m->y_player + 1;
		m->map[m->y_player][m->x_player] = 'P';
		m->count_c--;
		write_moves();
	}
	else if (m->map[m->y_player + 1][m->x_player] == 'E')
	{
		if (m->count_c == 0)
		{
			m->map[m->y_player][m->x_player] = '0';
			write_moves();
			write(1, "GOOOOOOOD GAME\n", 15);
			close_handler(m);
		}
	}
}
