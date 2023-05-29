#include "../so_long.h"
#include "../g_n_l/get_next_line.h"

char	**get_map(char *av[], t_map *map)
{
	char	*line;
	char	*long_line;
	char	*led;

	if (!strstr(av[1], ".ber"))
	{
		perror("\033[0;31mmap invalude");
		exit (0);
	}
	map->fd = open(av[1], O_RDONLY);
	long_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(map->fd);
		led = long_line;
		long_line = ft_strjoin(long_line, line);
		free(led);
		free (line);
		if (!line)
			break;
	}
	close(map->fd);
	return(ft_split(long_line, '\n'));
}

int	wid_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = -1;
		while(map->map[i][++j])
			if (map->map[i][j] != '0' && map->map[i][j] != '1' 
				&& map->map[i][j] != 'E' && map->map[i][j] != 'C' && map->map[i][j] != 'P')
			{
				write(1 ,"\033[0;31mmap invalude\n", 20);
				exit(1);
			}
			else if (map->map[i][j] == 'C')
				map->collect += 1;
			else if (map->map[i][j] == 'P')
			{
				map->x_play += i;
				map->y_play += j;
			}
		i++;
	}
	return (i);
}

static int	chaek_map(t_map *map)
{
	int	j;

	j = -1;
	while (map->map[0][++j])
		if (map->map[0][j] != '1')
			return (0);
	j = -1;
	while (map->map[map->width_map - 1][++j])
		if (map->map[map->width_map - 1][j] != '1')
			return (0);
	j = 0;
	while (map->map[++j][0] && j < map->width_map - 1)
		if (map->map[j][0] != '1')
			return (0);
	j = 0;
	while (map->map[++j][map->Heigt_map - 1] && j < map->width_map - 1)
		if (map->map[j][map->Heigt_map - 1] != '1')
			return (0);
	return (1);
}

void	init_map(t_map *map)
{
	map->fd = 0;
	map->collect = 0;
	map->x_play = 0;
	map->y_play = 0;
	map->Heigt_map = ft_strlen(map->map[0]);
	map->width_map = wid_map(map);
	map->mov = 0;
	if (!chaek_map(map))
	{
		write(1, "\033[0;31meroor in wall\n", 21);
		exit(1);
	}
}
