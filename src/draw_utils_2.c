/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:09:07 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/12 18:09:09 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_line *line)
{
	line->x = (line->x - line->y) * cos(1);
	line->y = (line->x + line->y) * sin(1) - line->z[0];
	line->dst[0] = (line->dst[0] - line->dst[1]) * cos(1);
	line->dst[1] = (line->dst[0] + line->dst[1]) * sin(1) - line->z[1];
}

void	add_shift(t_line *line, t_fdf *fdf)
{
	line->x += fdf->camera.shift_x;
	line->y += fdf->camera.shift_y;
	line->dst[0] += fdf->camera.shift_x;
	line->dst[1] += fdf->camera.shift_y;
}

void	add_zoom(t_line *line, t_fdf *fdf)
{
	line->x *= fdf->camera.zoom;
	line->y *= fdf->camera.zoom;
	line->dst[0] *= fdf->camera.zoom;
	line->dst[1] *= fdf->camera.zoom;
}

void	my_pixel_put_menu(t_menu *menu, int x, int y, int color)
{
	char	*dst;

	dst = menu->addr + (y * menu->len + x * (menu->bbp / 8));
	*(unsigned int *)dst = color;
}

void	my_pixel_put_bg(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->len + x * (fdf->bbp / 8));
	*(unsigned int *)dst = color;
}
