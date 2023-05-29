#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "mlx.h"
#include "/usr/local/include/mlx.h"


# define IMG_WALL "./image/wall.xpm"
# define IMG_BGD "./image/background.xpm"
# define IMG_PLAYER "./image/player.xpm"
# define IMG_COLLECT "./image/collect.xpm"
# define IMG_DOOR "./image/door.xpm"

# define A 0
# define S 1 
# define D 2
# define W 13

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

# define ESC 53

typedef struct s_map
{
    void    *mlx;
	void    *mlx_win;
    void    *img;
    int     fd;
    int     Heigt_map;
    int     width_map;
    int     x_play;
    int     y_play;
    int     collect;
    int     mov;
    char    **map;
}t_map;


void    so_long();
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);

char	**get_map(char *av[], t_map *map);
int     wid_map(t_map *map);
void	init_map(t_map *map);
void	put_image(t_map *map);

void    go_up(t_map *map);
void    go_down(t_map *map);
void    go_right(t_map *map);
void    go_left(t_map *map);

#endif