/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:39:21 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/03 11:39:21 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define SZ 32

typedef struct s_count{
	int		size_x;
	int		size_y;
	int		c_cnt;
	int		e_cnt;
	int		p_cnt;
}t_count;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		x_player;
	int		y_player;
	int		count_c;
	void	*player;
	void	*exit;
	void	*collectible;
	void	*wall;
	void	*emptyspace;
	char	**map;
}t_data;

typedef struct s_mapcopy
{
	int		cont_c;
	int		height;
	int		width;
	int		x_player;
	int		y_player;
	int		exit;
	char	**mapcopy;
}t_mapcopy;

char	**read_map(char *filename);
void	ft_error(char **map);
char	*ft_strjoin(char *line, char *buff);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		check_element_doubles(char **map);
int		check_regtangle(char **map);
int		check_walls(char **map);
int		check_file_is_valid(char *file_line);
void	libix(char **map);
void	to_right(t_data *m);
void	to_top(t_data *m);
void	to_left(t_data *m);
void	to_bottom(t_data *m);
void	ft_putnbr(int n);
int		key_hook(int keycode, t_data *m);
void	free_map(char **map);
void	free_images(t_data *m);
int		close_handler(t_data *m);
void	flood_fill(t_mapcopy *cp, int x, int y, int *count_c);
void	size_map(char **map, int *height, int *width);
void	copy_map(char **map, t_mapcopy *cp);
void	render_map(t_data *m);
void	ft_putnbr(int n);
char	*ft_strdup(const char *s);

#endif