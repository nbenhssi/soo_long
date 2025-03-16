#include "so_long.h"

void to_right(t_data **m)
{
    int width, height;
    width = sz;
    height = sz;

    *((*m)->player) = mlx_xpm_file_to_image((*m)->mlx, "./images/player.xpm", &width, &height);
	*((*m)->wall) = mlx_xpm_file_to_image((*m)->mlx, "./images/wall.xpm", &width, &height);
    if ((*m)->map[(*m)->y_player][(*m)->x_player+1] == '0')
    {
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->emptyspace),   (*m)->x_player * sz, (*m)->y_player * sz);
        (*m)->map[(*m)->y_player][(*m)->x_player] = '0';
        (*m)->x_player = (*m)->x_player + 1;
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->player), (*m)->x_player * sz, (*m)->y_player * sz);
    }
    else if ((*m)->map[(*m)->y_player][(*m)->x_player+1] == 'C')
    {
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->emptyspace), (*m)->x_player * sz, (*m)->y_player * sz);
        (*m)->map[(*m)->y_player][(*m)->x_player] = '0';
        (*m)->x_player = (*m)->x_player + 1;
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->player), (*m)->x_player * sz,(*m)->y_player * sz);
        (*m)->count_c--;
    }
    else if ( (*m)->map[(*m)->y_player][(*m)->x_player+1] == 'E')
    {
        printf("%d",(*m)->count_c);
        if ((*m)->count_c == 0)
        {
            (*m)->map[(*m)->y_player][(*m)->x_player] = '0';
            mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->emptyspace), (*m)->x_player * sz, (*m)->y_player * sz);
            exit(1);
        }
    }
}
void    to_top(t_data **m)
{
    int width, height;
    width = sz;
    height = sz;
    *((*m)->player) = mlx_xpm_file_to_image((*m)->mlx, "./images/player.xpm", &width, &height);
	*((*m)->wall) = mlx_xpm_file_to_image((*m)->mlx, "./images/wall.xpm", &width, &height);

    if ((*m)->map[(*m)->y_player-1][(*m)->x_player] == '0')
    {
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->emptyspace),   (*m)->x_player * sz, (*m)->y_player * sz);
        (*m)->map[(*m)->y_player][(*m)->x_player] = '0';
        (*m)->y_player = (*m)->y_player - 1;
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->player), (*m)->x_player * sz, (*m)->y_player * sz);
    }
    else if ((*m)->map[(*m)->y_player-1][(*m)->x_player] == 'C')
    {
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->emptyspace), (*m)->x_player * sz, (*m)->y_player * sz);
        (*m)->map[(*m)->y_player][(*m)->x_player] = '0';
        (*m)->y_player = (*m)->y_player - 1;
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->player), (*m)->x_player * sz,(*m)->y_player * sz);
        (*m)->count_c--;
    }
    else if ((*m)->map[(*m)->y_player-1][(*m)->x_player] == 'E')
    {
        if ( (*m)->count_c == 0)
        {
            (*m)->map[(*m)->y_player][(*m)->x_player] = '0';
            mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->emptyspace), (*m)->x_player * sz, (*m)->y_player * sz);
            exit(1);
        }
    }
}


void to_left(t_data **m)
{
    int width, height;
    width = sz;
    height = sz;

    *((*m)->player) = mlx_xpm_file_to_image((*m)->mlx, "./images/player.xpm", &width, &height);
	*((*m)->wall) = mlx_xpm_file_to_image((*m)->mlx, "./images/wall.xpm", &width, &height);
    if ((*m)->map[(*m)->y_player][(*m)->x_player-1] == '0')
    {
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->emptyspace),   (*m)->x_player * sz, (*m)->y_player * sz);
        (*m)->map[(*m)->y_player][(*m)->x_player] = '0';
        (*m)->x_player = (*m)->x_player - 1;
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->player), (*m)->x_player * sz, (*m)->y_player * sz);
    }
    else if ((*m)->map[(*m)->y_player][(*m)->x_player-1] == 'C')
    {
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->emptyspace), (*m)->x_player * sz, (*m)->y_player * sz);
        (*m)->map[(*m)->y_player][(*m)->x_player] = '0';
        (*m)->x_player = (*m)->x_player - 1;
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->player), (*m)->x_player * sz,(*m)->y_player * sz);
        (*m)->count_c--;
    }
    else if ((*m)->map[(*m)->y_player][(*m)->x_player-1] == 'E')
    {
        if ( (*m)->count_c == 0)
        {
            (*m)->map[(*m)->y_player][(*m)->x_player] = '0';
            mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->emptyspace), (*m)->x_player * sz, (*m)->y_player * sz);
            exit(1);
        }
    }
}

void    to_bottom(t_data **m)
{
    int width, height;
    width = sz;
    height = sz;
    *((*m)->player) = mlx_xpm_file_to_image((*m)->mlx, "./images/player.xpm", &width, &height);
	*((*m)->wall) = mlx_xpm_file_to_image((*m)->mlx, "./images/wall.xpm", &width, &height);

    if ((*m)->map[(*m)->y_player+1][(*m)->x_player] == '0')
    {
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->emptyspace),   (*m)->x_player * sz, (*m)->y_player * sz);
        (*m)->map[(*m)->y_player][(*m)->x_player] = '0';
        (*m)->y_player = (*m)->y_player + 1;
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->player), (*m)->x_player * sz, (*m)->y_player * sz);
    }
    else if ((*m)->map[(*m)->y_player+1][(*m)->x_player] == 'C')
    {
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->emptyspace), (*m)->x_player * sz, (*m)->y_player * sz);
        (*m)->map[(*m)->y_player][(*m)->x_player] = '0';
        (*m)->y_player = (*m)->y_player + 1;
        mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->player), (*m)->x_player * sz,(*m)->y_player * sz);
        (*m)->count_c--;
    }
    else if ((*m)->map[(*m)->y_player+1][(*m)->x_player] == 'E')
    {
        if ( (*m)->count_c == 0)
        {
            (*m)->map[(*m)->y_player][(*m)->x_player] = '0';
            mlx_put_image_to_window((*m)->mlx, (*m)->win, *((*m)->emptyspace), (*m)->x_player * sz, (*m)->y_player * sz);
            exit(1);
        }
    }
}
