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
#include "/mnt/c/Users/User/OneDrive/Desktop/so_long/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <string.h>

#define sz 32

typedef struct s_count{
	int		size_x;
	int		size_y;
	int		c_cnt;
	int		e_cnt;
	int		p_cnt;
}t_count;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		x_player;
	int		y_player;
	int		count_c;
	void	**player;
	void    **exit;
	void	**collectible;
	void	**wall;
	char	**map;
	char	**emptyspace;
	t_image	img;
}t_data;

static int moves;

char	**read_map(char *filename);
void	ft_error(char **map);
char	*ft_strjoin(char *line, char *buff);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		check_element_doubles(char **map);
int		check_regtangle(char  **map);
int		check_walls(char **map);
int		check_file_is_valid(char *file_line);
void    libix(char **map);
void	to_right(t_data **m);
void    to_top(t_data **m);
void 	to_left(t_data **m);
void    to_bottom(t_data **m);

#endif