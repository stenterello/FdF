#include "fdf.h"

void	isometric(float *x, float *y, float dst[2], int z[2])
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(1) - z[0];
	dst[0] = (dst[0] - dst[1]) * cos(1);
	dst[1] = (dst[0] + dst[1]) * sin(1) - z[1];
    //rotate_x(fdf, y, &z[0]);
}

void	add_shift(float *x, float *y, float dst[2], t_fdf *fdf)
{
	*x += fdf->camera.shift_x;
	*y += fdf->camera.shift_y;
	dst[0] += fdf->camera.shift_x;
	dst[1] += fdf->camera.shift_y;
}

void	add_zoom(float *x, float *y, float dst[2], t_fdf *fdf)
{
	*x *= fdf->camera.zoom;
	*y *= fdf->camera.zoom;
	dst[0] *= fdf->camera.zoom;
	dst[1] *= fdf->camera.zoom;
}

void	my_pixel_put(t_menu *menu, int x, int y, int color)
{
	char	*dst;

	dst = menu->addr + (y * menu->len + x * (menu->bbp / 8));
	*(unsigned int *)dst = color;
}
