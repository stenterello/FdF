#ifndef FDF_H
# define FDF_H

//# include "../mlx_linux/mlx.h"
//# include "../mlx_linux/mlx_int.h"
# include <mlx.h>
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

typedef struct s_mouse
{
	int	    is_pressed;
	int	    is_scrolling;
	int		x;
	int		y;
    int		prev_x;
    int		prev_y;
}				t_mouse;

typedef struct s_menu
{
	int		width;
	int		height;
	int		color;
	void	*img;
	char	*addr;
	int		bbp;
	int		len;
	int		end;
}				t_menu;

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
	int		scale_z;
	double	alpha;
	double	beta;
	double	gamma;
	t_mat	matrix;
	t_menu	menu;
	t_mouse	mouse;
}				t_fdf;

void	die(char *str);
void	read_map(char *file_name, t_fdf *fdf);
void	fill_line(int *matrix, char *line);
void	init_fdf(t_fdf *fdf);
void	open_win(t_fdf *fdf);
void	draw(t_fdf *fdf);
void	isometric(float *x, float *y, float dst[2], int z[2]);
void	add_shift(float *x, float *y, float dst[2], t_fdf *fdf);
void	add_zoom(float *x, float *y, float dst[2], t_fdf *fdf);
void	define_delta(float *x, float *y, float dst[2], float d_xy[3]);
int		to_continue(float d_xy[3], float *x, float *y, float dst[2]);
int		color_choose(int z);
void	free_matrix(t_fdf *fdf);
void	add_events(t_fdf *fdf);
void    my_pixel_put(t_menu *menu, int x, int y, int color);
int	    mouse_press(int keycode, int x, int y, void *param);
void	rotate_x(float *y, int *z, double alpha);

#endif