#include "fdf.h"

static void	isometric(float *x, float *y, float dst[2], int z[2])
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(1) - z[0];
	dst[0] = (dst[0] - dst[1]) * cos(1);
	dst[1] = (dst[0] + dst[1]) * sin(1) - z[1];
}

static void	add_shift(float *x, float *y, float dst[2], t_fdf *fdf)
{
	*x += fdf->shift_x;
	*y += fdf->shift_y;
	dst[0] += fdf->shift_x;
	dst[1] += fdf->shift_y;
}

static void	add_zoom(float *x, float *y, float dst[2], t_fdf *fdf)
{
	*x *= fdf->zoom;
	*y *= fdf->zoom;
	dst[0] *= fdf->zoom;
	dst[1] *= fdf->zoom;
}

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
	add_shift(&x, &y, dst, fdf);
	isometric(&x, &y, dst, z);
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
			{
				dst[0] = xy[0] + 1;
				dst[1] = xy[1];
				bresenham(xy, dst, fdf);
			}
			if (xy[1] < fdf->matrix.rows - 1)
			{
				dst[0] = xy[0];
				dst[1] = xy[1] + 1;
				bresenham(xy, dst, fdf);
			}
			xy[0]++;
		}
		xy[1]++;
	}
}
