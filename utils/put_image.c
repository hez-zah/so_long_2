#include "../so_long.h"

void	put_aid_image(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
	{
		map->img = mlx_xpm_file_to_image(map->mlx, IMG_WALL, &map->Heigt_map , &map->width_map);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, j * 60, i * 60);
	}
	else if (map->map[i][j] == '0')
	{
		map->img = mlx_xpm_file_to_image(map->mlx, IMG_BGD, &map->Heigt_map , &map->width_map);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, j * 60, i * 60);
	}
	else if (map->map[i][j] == 'P')
	{
		map->img = mlx_xpm_file_to_image(map->mlx, IMG_PLAYER, &map->Heigt_map , &map->width_map);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, j * 60, i * 60);
	}
	else if (map->map[i][j] == 'C')
	{
		map->img = mlx_xpm_file_to_image(map->mlx, IMG_COLLECT, &map->Heigt_map , &map->width_map);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, j * 60, i * 60);
	}
	else if (map->map[i][j] == 'E')
	{
		map->img = mlx_xpm_file_to_image(map->mlx, IMG_DOOR, &map->Heigt_map , &map->width_map);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, j * 60, i * 60);
	}
}

void	put_image(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			put_aid_image(map, i, j);
	}
}