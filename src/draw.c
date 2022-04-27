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

void	prepare(t_line *line, t_fdf *fdf)
{
	line->orig_z[0] = fdf->matrix.matrix[(int)line->xy[1]][(int)line->xy[0]];
	line->orig_z[1] = fdf->matrix.matrix[(int)line->dst[1]][(int)line->dst[0]];
	if (line->orig_z[0] && !line->orig_z[1])
		line->color = fdf->end_color;
	else
		line->color = fdf->start_color;
	line->x = line->xy[0];
	line->y = line->xy[1];
	line->z[0] = line->orig_z[0] * fdf->camera.zoom / fdf->camera.z_divisor;
	line->z[1] = line->orig_z[1] * fdf->camera.zoom / fdf->camera.z_divisor;
	add_zoom(line, fdf);
	rotate(line, fdf, 0);
	rotate(line, fdf, 1);
	if (fdf->iso)
		isometric(line);
	add_shift(line, fdf);
	define_delta(line);
	line->len = virtual_bresenham(line);
	line->unit = line->len / (float)255;
	if (line->unit > 1.49)
		line->unit = 1.49;
}

void	increasing_color(t_fdf *fdf, t_line *line, int *i)
{
	mlx_pixel_put(fdf->mlx, fdf->win, line->x, line->y, line->color);
	if (line->unit < (*i)++)
	{
		line->color -= 65536 * (int)((float)*i / line->unit);
		line->color += 256 * (int)((float)*i / line->unit);
		*i = 0x00;
	}
}

void	decreasing_color(t_fdf *fdf, t_line *line, int *i)
{
	mlx_pixel_put(fdf->mlx, fdf->win, line->x, line->y, line->color);
	if (line->unit < (*i)++)
	{
		if (line->color + 65536 * (int)((float)*i / line->unit) < 0x00FF0000)
		{
			line->color += 65536 * (int)((float)*i / line->unit);
			line->color -= 256 * (int)((float)*i / line->unit);
		}
		*i = 0x00;
	}
}

void	bresenham(t_line *line, t_fdf *fdf)
{
	int	i;

	i = 0x00;
	prepare(line, fdf);
	while (to_continue(line))
	{
		if (line->orig_z[0] && line->orig_z[1])
			mlx_pixel_put(fdf->mlx, fdf->win, line->x, line->y, fdf->end_color);
		else if (line->orig_z[0] || line->orig_z[1])
		{
			if (line->orig_z[1])
				increasing_color(fdf, line, &i);
			else if (line->orig_z[0])
				decreasing_color(fdf, line, &i);
		}
		else
			mlx_pixel_put(fdf->mlx, fdf->win, line->x,
				line->y, fdf->start_color);
		line->x += line->d_xy[0];
		line->y += line->d_xy[1];
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
	mlx_string_put(fdf->mlx, fdf->win, 20, 120, 0x00FFFFFF,
		"Zoom: PageUp/PageDown or Scroll");
	mlx_string_put(fdf->mlx, fdf->win, 20, 200, 0x00FFFFFF, "Flatten: 7 / 9");
	mlx_string_put(fdf->mlx, fdf->win, 20, 270, 0x00FFFFFF,
		"Rotate: Mouse or 1-4, 2-5");
	mlx_string_put(fdf->mlx, fdf->win, 20, 350, 0x00FFFFFF,
		"Change Point of View: P, O");
	mlx_string_put(fdf->mlx, fdf->win, 20, 420, 0x00FFFFFF,
		"Reset: I");
}
