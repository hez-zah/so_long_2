#include "../so_long.h"

void    min_put_image(t_map *map, int i, int j)
{
    mlx_destroy_image(map->mlx, map->img);
    map->img = mlx_xpm_file_to_image(map->mlx, IMG_BGD, &map->Heigt_map , &map->width_map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, map->y_play * 60, map->x_play * 60);
    map->img = mlx_xpm_file_to_image(map->mlx, IMG_PLAYER, &map->Heigt_map , &map->width_map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, (map->y_play  + i) * 60, (map->x_play + j) * 60);
}


void    go_up(t_map *map)
{
    if (map->map[map->x_play - 1][map->y_play] == '0' || map->map[map->x_play - 1][map->y_play] == 'C')
    {
        if (map->map[map->x_play - 1][map->y_play] == 'C')
            map->collect -= 1;
        map->map[map->x_play - 1][map->y_play] = 'P';
        map->map[map->x_play][map->y_play] = '0';
        min_put_image(map, 0, -1);
        map->x_play -= 1;
        map->mov += 1;
        printf("\033[0;34mnombre move : %d\n", map->mov);
    }
    else if (map->map[map->x_play - 1][map->y_play] == 'E' && !map->collect)
    {
        map->mov += 1;
        printf("\033[0;34mnombre move : %d\n\033[0;35mBravo\n", map->mov);
        exit(0);
    }
}

void    go_down(t_map *map)
{
    if (map->map[map->x_play + 1][map->y_play] == '0' || map->map[map->x_play + 1][map->y_play] == 'C')
    {
        if (map->map[map->x_play + 1][map->y_play] == 'C')
            map->collect -= 1;
        map->map[map->x_play + 1][map->y_play] = 'P';
        map->map[map->x_play][map->y_play] = '0';
        min_put_image(map, 0, 1);
        map->x_play += 1;
        map->mov += 1;
        printf("\033[0;34mnombre move : %d\n", map->mov);
    }
    else if (map->map[map->x_play + 1][map->y_play] == 'E' && !map->collect)
    {
        map->mov += 1;
        printf("\033[0;34mnombre move : %d\n\033[0;35mBravo\n", map->mov);
        exit(0);
    }
}

void    go_right(t_map *map)
{
    if (map->map[map->x_play][map->y_play + 1] == '0' || map->map[map->x_play][map->y_play + 1] == 'C')
    {
        if (map->map[map->x_play][map->y_play + 1] == 'C')
            map->collect -= 1;
        map->map[map->x_play][map->y_play + 1] = 'P';
        map->map[map->x_play][map->y_play] = '0';
        min_put_image(map, 1, 0);
        map->y_play += 1;
        map->mov += 1;
        printf("\033[0;34mnombre move : %d\n", map->mov);
    }
    else if (map->map[map->x_play][map->y_play + 1] == 'E' && !map->collect)
    {
        map->mov += 1;
        printf("\033[0;34mnombre move : %d\n\033[0;35mBravo\n", map->mov);
        exit(0);
    }
}

void    go_left(t_map *map)
{
    if (map->map[map->x_play][map->y_play - 1] == '0' || map->map[map->x_play][map->y_play - 1] == 'C')
    {
        if (map->map[map->x_play][map->y_play - 1] == 'C')
            map->collect -= 1;
        map->map[map->x_play][map->y_play - 1] = 'P';
        map->map[map->x_play][map->y_play] = '0';
        min_put_image(map, -1, 0);
        map->y_play -= 1;
        map->mov += 1;
        printf("\033[0;34mnombre move : %d\n", map->mov);
    }
    else if (map->map[map->x_play][map->y_play - 1] == 'E' && !map->collect)
    {
        map->mov += 1;
        printf("\033[0;34mnombre move : %d\n\033[0;35mBravo\n", map->mov);
        exit(0);
    }
}
