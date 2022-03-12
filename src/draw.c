/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:08:53 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/12 18:08:55 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(const float xy[2], float dst[2], t_fdf *fdf)
{
	float	d_xy[3];
	int		z[2];
	float	x;
	float	y;
	int		color;
	float	orig_z[2];
	int		i;

	i = 0x00;
	orig_z[0] = fdf->matrix.matrix[(int)xy[1]][(int)xy[0]];
	orig_z[1] = fdf->matrix.matrix[(int)dst[1]][(int)dst[0]];
	color = fdf->start_color;
	x = xy[0];
	y = xy[1];
	z[0] = orig_z[0] * fdf->camera.zoom / fdf->camera.z_divisor;
	z[1] = orig_z[1] * fdf->camera.zoom / fdf->camera.z_divisor;
	add_zoom(&x, &y, dst, fdf);
	rotate(fdf, &x, &y, &z[0]);
	rotate(fdf, &dst[0], &dst[1], &z[1]);
	if (fdf->iso)
		isometric(&x, &y, dst, z);
	add_shift(&x, &y, dst, fdf);
	define_delta(&x, &y, dst, d_xy);
	while (to_continue(d_xy, &x, &y, dst))
	{
        fdf->bench_color = fdf->start_color;
		if (orig_z[0] && orig_z[1])
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, fdf->end_color);
		else if (orig_z[0] || orig_z[1])
		{
			if (orig_z[1])
			{
				mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
				i++;
				if (d_xy[2] / 255 < i)
				{
					color -= 65536;
					color += 256;
					i = 0x00;
				}
			}
			else if (orig_z[0])
			{
				mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
				i++;
				if (d_xy[2] / 255 < i)
				{
					color += 65536;
					color -= 256;
					i = 0x00;
				}
			}
		}
		else
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, fdf->start_color);
		x += d_xy[0];
		y += d_xy[1];
	}
}

void	draw_menu(t_fdf *fdf)
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
			my_pixel_put_menu(&fdf->menu, i2++, i, 0x0000c20d);
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->menu.img, 0, 0);
	mlx_string_put(fdf->mlx, fdf->win, 20, 50, 0x00FFFFFF, "Move plan: WASD");
	mlx_string_put(fdf->mlx, fdf->win, 20, 120, 0x00FFFFFF, "Zoom: PageUp/PageDown or Scroll");
	mlx_string_put(fdf->mlx, fdf->win, 20, 200, 0x00FFFFFF, "Flatten: 7 / 9");
	mlx_string_put(fdf->mlx, fdf->win, 20, 270, 0x00FFFFFF, "Rotate: Mouse or 4, 5, 1, 2");
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

void	draw_plane(t_fdf *fdf)
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
}

void	draw(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_plane(fdf);
	draw_menu(fdf);
}
