#include "fdf.h"

void    rotate(t_fdf *fdf, float *x, float *y, int *z)
{
    rotate_x(fdf, y, z);
    rotate_y(fdf, x, z);
    rotate_z(fdf, x, y);
}

void	bresenham(const float xy[2], float dst[2], t_fdf *fdf)
{
	float	d_xy[3];
	int		z[2];
	float	x;
	float	y;
	int		color;

	

	z[0] = fdf->matrix.matrix[(int)xy[1]][(int)xy[0]];
	z[1] = fdf->matrix.matrix[(int)dst[1]][(int)dst[0]];
	color = color_choose(z[0]);
	x = xy[0];
	y = xy[1];
	add_zoom(&x, &y, dst, fdf);
	z[0] *= fdf->camera.zoom / fdf->camera.z_divisor;
	z[1] *= fdf->camera.zoom / fdf->camera.z_divisor;
    rotate(fdf, &x, &y, &z[0]);
	rotate(fdf, &dst[0], &dst[1], &z[1]);
	if (fdf->iso)
		isometric(&x, &y, dst, z);
	add_shift(&x, &y, dst, fdf);
	define_delta(&x, &y, dst, d_xy);
	while (to_continue(d_xy, &x, &y, dst))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
		x += d_xy[0];
		y += d_xy[1];
		if (x > fdf->win_width || x < 0
			|| y > fdf->win_height || y < 0)
			break ;
	}
}

void	menu(t_fdf *fdf)
{
	int	i;
	int	i2;
	int	x;
	int	y;

	fdf->menu.img = mlx_new_image(fdf->mlx, fdf->menu.width, fdf->menu.height);
	fdf->menu.addr = mlx_get_data_addr(fdf->menu.img, &fdf->menu.bbp,
			&fdf->menu.len, &fdf->menu.end);
	i = 0;
	while (i < fdf->menu.height)
	{
		i2 = 0;
		while (i2 < fdf->menu.width)
			my_pixel_put_menu(&fdf->menu, i2++, i, 0x0000c20d);
		i++;
	}
	x = 20;
	y = 50;
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->menu.img, 0, 0);
	mlx_string_put(fdf->mlx, fdf->win, x, y, 0x00FFFFFF, "Move plan:");
	x += 20;
	y += 50;
	mlx_string_put(fdf->mlx, fdf->win, x, y, 0x00FFFFFF, "WASD");
	x -= 20;
	y -= 50;
	mlx_string_put(fdf->mlx, fdf->win, 20, 125, 0x00FFFFFF, "Zoom:");
	x += 20;
	y += 50;
	mlx_string_put(fdf->mlx, fdf->win, 70, 150, 0x00FFFFFF, "PageUp/PageDown");
}

static void	first_draw(float xy[2], float dst[2], t_fdf *fdf)
{
	dst[0] = xy[0] + 1;
	dst[1] = xy[1];
	bresenham(xy, dst, fdf);
}

static void	second_draw(float xy[2], float dst[2], t_fdf *fdf)
{
	dst[0] = xy[0];
	dst[1] = xy[1] + 1;
	bresenham(xy, dst, fdf);
}

void	draw_background(t_fdf *fdf)
{
	int	i;
	int	j;

	fdf->img = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bbp,
		&fdf->len, &fdf->end);
	i = 0;
	while (i < fdf->win_height)
	{
		j = 0;
		while (j < fdf->win_width)
		{
			my_pixel_put_bg(fdf, j, i, 0x00363d36);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	draw(t_fdf *fdf)
{
	float	xy[2];
	float	dst[2];

	draw_background(fdf);
	xy[1] = 0;
	while (xy[1] < fdf->matrix.rows)
	{
		xy[0] = 0;
		while (xy[0] < fdf->matrix.cols)
		{
			if (xy[0] < fdf->matrix.cols - 1)
				first_draw(xy, dst, fdf);
			if (xy[1] < fdf->matrix.rows - 1)
				second_draw(xy, dst, fdf);
			xy[0]++;
		}
		xy[1]++;
	}
	menu(fdf);
}
