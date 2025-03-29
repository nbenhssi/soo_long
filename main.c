#include <stddef.h>
#include <stdio.h>

typedef struct s_data
{
    void *mlx;
    void *win;
    char **map;
    int height;
    int width;
} t_data;

void fct2(int *n)
{
    *n = 9;
}
void fct(int *a)
{
    *a = 2;
    fct2(a);
}

int main()
{
    int i;

    i = 0;
    fct(&i);
    printf("%d\n", i);
    return 0;
}



static void	handle_path_error(char **map, t_mapcopy *cp, int count_c)
{
	if (cp->exit != 1)
		write(2, "Error\nConnot exit\n", 19);
	else
		write(2, "Error\nConnot\n", 14);
	ft_error(map);
}

int	main(int argc, char **argv)
{
	char		**map;
	t_mapcopy	cp;
	int			count_c;

	map = NULL;
	count_c = 0;
	cp.exit = 0;
	cp.cont_c = 0;
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
		handle_path_error(map, &cp, count_c);
	return (libix(map), 0);
}


static void	init_player_and_collectibles(char **map, t_mapcopy *cp, int j, int i)
{
	if (map[j][i] == 'P')
	{
		cp->x_player = i;
		cp->y_player = j;
	}
	if (map[j][i] == 'C')
		cp->cont_c++;
}

void	copy_map(char **map, t_mapcopy *cp)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	cp->height = 0;
	cp->width = 0;
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
			init_player_and_collectibles(map, cp, j, i++);
		j++;
	}
	cp->mapcopy[j] = NULL;
}
