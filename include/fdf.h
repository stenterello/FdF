#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"


typedef struct  s_map
{
    int width;
    int height;
    int *coord;
}               t_map;


typedef struct s_fdf
{
    void    *mlx;
    void    *win;
    void    *img;
    char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    t_map   *map;
}              t_fdf;

void    die(char *str);
void    init_map(char *file_name, t_map *map);
void	checks(char *file_name, t_map *map);
void	check_characters(char *line);
void	one_by_one(char *line);

#endif