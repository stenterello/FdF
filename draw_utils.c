#include "include/fdf.h"

int	ft_abs(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

void	define_increment(t_point *p, int *dst, int *s, int *q)
{
	if (p->x > dst[0])
		*q = -1;
	else
		*q = 1;
	if (p->y > dst[1])
		*s = -1;
	else
		*s = 1;
}

void	next_p(t_point *p, int dst[2], t_fdf *fdf)
{
	int	d_x;
	int	d_y;
	int	d;
	int	s;
	int	q;
	int	a;
	int	b;
	int	i;
	int	swap;

	swap = 0;
	i = 0;
	d_x = dst[0] - p->x;
	d_y = dst[1] - p->y;
	if (ft_abs(d_x) < ft_abs(d_y))
	{
		swap = d_x;
		d_x = d_y;
		d_y = swap;
		swap = 1;
	}
	a = ft_abs(d_y);
	b = -ft_abs(d_x);
	d = 2 * a + b;
	define_increment(p, dst, &s, &q);
	while (i < -b)
	{
		if (d > 0)
		{
			p->x += q;
			p->y += s;
			d += 2 * (a + b);
		}
		else
		{
			p->x += q;
			if (swap)
			{
				p->y += s;
				p->x -= q;
			}
			d += 2 * a;
		}
		mlx_pixel_put(fdf->mlx, fdf->win, p->x, p->y, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	draw(t_fdf *fdf, t_map *map, t_point *p, int *dst)
{
	(void)map;
	fdf->img = mlx_new_image(fdf->mlx, 0, 0);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->linlen, &fdf->end);
	next_p(p, dst, fdf);
}

void	draw_plane(t_plane *plane, t_fdf *fdf)
{
	t_point	angle;
	int		dst[2];
	int		i;

	i = 0;
	fdf->img = mlx_new_image(fdf->mlx, 10, 10);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->linlen, &fdf->end);
	while (i < 7)
	{
		angle.x = plane->angles[i];
		angle.y = plane->angles[i + 1];
		if (i + 3 <= 7)
		{
			dst[0] = plane->angles[i + 2];
			dst[1] = plane->angles[i + 3];
		}
		else
		{
			dst[0] = plane->angles[0];
			dst[1] = plane->angles[1];
		}
		next_p(&angle, dst, fdf);
		i += 2;
	}
}
