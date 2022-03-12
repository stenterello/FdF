#include "fdf.h"

float	ft_abs(float c)
{
	if (c < 0)
		return (-c);
	return (c);
}

float	get_max_delta(float ret[3])
{
	if (ft_abs(ret[0]) > ft_abs(ret[1]))
		return (ft_abs(ret[0]));
	return (ft_abs(ret[1]));
}

void	define_delta(float *x, float *y, float dst[2], float d_xy[3])
{
	d_xy[0] = dst[0] - *x;
	d_xy[1] = dst[1] - *y;
	d_xy[2] = get_max_delta(d_xy);
	d_xy[0] /= d_xy[2];
	d_xy[1] /= d_xy[2];
}

int	to_continue(float d_xy[3], float *x, float *y, float dst[2])
{
	if (get_max_delta(d_xy) == ft_abs(d_xy[0]))
	{
		if (d_xy[0] > 0 && *x <= dst[0])
			return (1);
		if (d_xy[0] < 0 && *x >= dst[0])
			return (1);
	}
	else if (get_max_delta(d_xy) == ft_abs(d_xy[1]))
	{
		if (d_xy[1] > 0 && *y <= dst[1])
			return (1);
		if (d_xy[1] < 0 && *y >= dst[1])
			return (1);
	}
	return (0);
}
