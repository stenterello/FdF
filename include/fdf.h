#ifndef FDF_H
# define FDF_H

//# include "<mlx.h>"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_map
{
	int	width;
	int	height;
	int	*coord;
	int	**matrix;
}				t_map;

typedef struct s_plane
{
	int	angles[8];
	int	width;
	int	height;
}				t_plane;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		linlen;
	int		end;
	t_map	*map;
}				t_fdf;

void	die(char *str);
void	init_map(char *file_name, t_map *map);
void	checks(char *file_name, t_map *map);
void	check_characters(char *line, t_map *map);
void	one_by_one(char *line, t_map *map);
int		ft_nbrlen(int n);
int		*get_nums(char *line, t_map *map);
void	fill_matrix(t_map *map, char *line);
void	one_by_one(char *line, t_map *map);
int		count_len(char *text, int *i);
void	alloc_matrix(t_map *map, int width, int height);
void	free_matrix(t_map *map);
int		close_window(int keycode, t_fdf *fdf);
int		close_window_with_x(t_fdf *fdf);
void	draw_plane(t_plane *plane, t_fdf *fdf);
void	draw(t_fdf *fdf, t_map *map, t_point *p, int *dst);
void	next_p(t_point *p, int dst[2], t_fdf *fdf);
void	define_increment(t_point *p, int *dst, int *s, int *q);
int		ft_abs(int c);

#endif
