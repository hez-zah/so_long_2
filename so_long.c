#include "so_long.h"
#include "g_n_l/get_next_line.h"

int keyhook(int keycode, t_map *map)
{
	if (keycode == W || keycode == UP)
		go_up(map);
	else if (keycode == S || keycode == DOWN)
		go_down(map);
	else if (keycode == D || keycode == RIGHT)
		go_right(map);
	else if (keycode == A || keycode == LEFT)
		go_left(map);
	else if (keycode == ESC)
		exit(1);
	return (1);
}

int mouse_hook(int keymose, t_map *map)
{
	if (keymose == 1)
	{
		printf("----->\n");
		exit (0);
	}
	return(1);
}

int main(int ac, char *av[])
{
	t_map map;
	int i;
	int j;

	if (ac != 2)
	{
		write(1, "\033[0;32mnombre d'argumet invalude", 33);
		exit(0);
	}
	map.map = get_map(av, &map);
	if (!map.map[0])
		exit(1);
	init_map(&map);
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, map.Heigt_map * 60, map.width_map * 60, "so_long");
	map.img = mlx_new_image(map.mlx, map.Heigt_map * 60, map.width_map * 60);
	put_image(&map);
	mlx_hook(map.mlx_win, 2, 1L << 0, keyhook, &map);
	mlx_mouse_hook(map.mlx_win, mouse_hook, &map);
	mlx_loop(map.mlx);
	mlx_destroy_window(map.mlx, map.mlx_win);
}

