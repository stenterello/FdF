#include "fdf.h"

void	rotate_x(t_fdf *fdf, float *y, int *z)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(fdf->camera.alpha) + *z * sin(fdf->camera.alpha);
	*z = -prev_y * sin(fdf->camera.alpha) + *z * cos(fdf->camera.alpha);
}

void	rotate_y(t_fdf *fdf, float *x, int *z)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(fdf->camera.beta) + *z * sin(fdf->camera.beta);
	*z = -prev_x * sin(fdf->camera.beta) + *z * cos(fdf->camera.beta);
}

void	rotate_z(t_fdf *fdf, float *x, float *y)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(fdf->camera.gamma) - prev_y * sin(fdf->camera.gamma);
	*y = prev_y * sin(fdf->camera.gamma) + prev_y * cos(fdf->camera.gamma);
}

void	rotate(t_fdf *fdf, float *x, float *y, int *z)
{
	int	prev_x;
	int	prev_y;
	int	prev_z;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	rotate_x(fdf, y, z);
	rotate_y(fdf, x, z);
	rotate_z(fdf, x, y);
}
