#include "fdf.h"

void	bresenham(const float xy[2], float dst[2], t_fdf *fdf)
{
	float	d_xy[3];
	int		z[2];
	float	x;
	float	y;

	z[0] = fdf->matrix.matrix[(int)xy[1]][(int)xy[0]];
	z[1] = fdf->matrix.matrix[(int)dst[1]][(int)dst[0]];
	x = xy[0];
	y = xy[1];
	add_zoom(&x, &y, dst, fdf);
	isometric(&x, &y, dst, z);
	add_shift(&x, &y, dst, fdf);
	define_delta(&x, &y, dst, d_xy);
	while (to_continue(d_xy, &x, &y, dst))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, color_choose(z[0]));
		x += d_xy[0];
		y += d_xy[1];
		if (x > fdf->win_width || x < 0
			|| y > fdf->win_height || y < 0)
			break ;
	}
}

static void	menu(t_fdf *fdf)
{
	int	i;
	int	i2;

	fdf->menu.img = mlx_new_image(fdf->mlx, fdf->menu.width, fdf->menu.height);
	fdf->menu.addr = mlx_get_data_addr(fdf->menu.img, &fdf->menu.bbp,
			&fdf->menu.len, &fdf->menu.end);
	i = 0;
	while (i < fdf->menu.height)
	{
		i2 = 0;
		while (i2 < fdf->menu.width)
			my_pixel_put(&fdf->menu, i2++, i, 0xC16756);
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->menu.img, 0, 0);
	mlx_string_put(fdf->mlx, fdf->win, 20, 50, 0x00FFFFFF, "Move plan:");
	mlx_string_put(fdf->mlx, fdf->win, 130, 75, 0x00FFFFFF, "WASD");
	mlx_string_put(fdf->mlx, fdf->win, 20, 125, 0x00FFFFFF, "Zoom:");
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

void	draw(t_fdf *fdf)
{
	float	xy[2];
	float	dst[2];

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
