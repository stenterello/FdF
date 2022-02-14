#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_mat
{
	int	cols;
	int	rows;
	int	**matrix;
}				t_mat;

typedef struct s_fdf
{
	float	x;
	float	y;
	float	z;
	int		rows;
	int		columns;
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	int		shift_x;
	int		shift_y;
	int		zoom;
	t_mat	matrix;
}				t_fdf;

void	die(char *str);
void	read_map(char *file_name, t_fdf *fdf);
void	fill_line(int *matrix, char *line);
void	init_fdf(t_fdf *fdf);
void	open_win(t_fdf *fdf);
void	draw(t_fdf *fdf);
void	define_delta(float *x, float *y, float dst[2], float d_xy[3]);
int		to_continue(float d_xy[3], float *x, float *y, float dst[2]);
int		color_choose(int z);

#endif
