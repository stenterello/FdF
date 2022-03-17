/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:09:43 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/12 18:09:45 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		is_pressed;
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

typedef struct s_camera
{
	double	alpha;
	double	beta;
	double	gamma;
	float	shift_x;
	float	shift_y;
	float	zoom;
	float	z_divisor;
}				t_camera;

typedef struct s_line
{
	float	xy[2];
	float	dst[2];
	float	d_xy[3];
	float	z[2];
	float	x;
	float	y;
	int		color;
	int		orig_z[2];
	int		len;
	float	virtual_x;
	float	virtual_y;
	double	unit;
}				t_line;

typedef struct s_fdf
{
	float		x;
	float		y;
	float		z;
	int			rows;
	int			columns;
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	int			scale_z;
	void		*img;
	char		*addr;
	int			bbp;
	int			len;
	int			end;
	int			iso;
	int			start_color;
	int			bench_color;
	int			end_color;
	t_mat		matrix;
	t_menu		menu;
	t_mouse		mouse;
	t_camera	camera;
}				t_fdf;

void	die(char *str);
void	read_map(char *file_name, t_fdf *fdf);
void	fill_line(int *matrix, char *line);
void	init_fdf(t_fdf *fdf);
void	init_camera(t_fdf *fdf);
void	init_mouse(t_fdf *fdf);
void	open_win(t_fdf *fdf);
void	bresenham(t_line *line, t_fdf *fdf);
void	draw(t_fdf *fdf);
void	draw_plane(t_fdf *fdf);
void	draw_menu(t_fdf *fdf);
void	draw_background(t_fdf *fdf);
void	first_draw(t_line *line, t_fdf *fdf);
void	second_draw(t_line *line, t_fdf *fdf);
void	isometric(t_line *line);
void	add_shift(t_line *line, t_fdf *fdf);
void	add_zoom(t_line *line, t_fdf *fdf);
void	define_delta(t_line *line);
int		to_continue(t_line *line);
int		color_choose(const float xy[2], float dst[2], float d_xy[2]);
void	free_matrix(t_fdf *fdf);
void	add_events(t_fdf *fdf);
void	my_pixel_put_menu(t_menu *menu, int x, int y, int color);
void	my_pixel_put_bg(t_fdf *fdf, int x, int y, int color);
int		mouse_press(int keycode, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
int		mouse_release(int keycode, int x, int y, void *param);
void	rotate_x(t_fdf *fdf, float *y, float *z);
void	rotate_y(t_fdf *fdf, float *x, float *z);
void	rotate_z(t_fdf *fdf, float *x, float *y);
void	rotate(t_line *line, t_fdf *fdf, int flag);
void	change_angle_alpha(t_fdf *fdf, int flag);
void	change_angle_beta(t_fdf *fdf);
void	change_angle_gamma(t_fdf *fdf);
float	ft_abs(float c);
void	move(t_fdf *fdf, int keycode);
void	zoom(t_fdf *fdf, int keycode);
void	flatten(t_fdf *fdf, int keycode);
int		virtual_bresenham(t_line *line);
int		to_continue_virtual(t_line *line);
float	get_max_delta(float ret[3]);
void	flat(t_fdf *fdf);
void	profile(t_fdf *fdf);
void	return_iso(t_fdf *fdf);

#endif
