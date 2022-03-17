/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:28:41 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/16 19:28:41 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_fdf *fdf, int keycode)
{
	if (keycode == 0)
		fdf->camera.shift_x -= 5;
	else if (keycode == 2)
		fdf->camera.shift_x += 5;
	else if (keycode == 13)
		fdf->camera.shift_y -= 5;
	else if (keycode == 1)
		fdf->camera.shift_y += 5;
	draw(fdf);
}

void	zoom(t_fdf *fdf, int keycode)
{
	if (keycode == 116 || keycode == 4)
		fdf->camera.zoom += 1;
	else
		fdf->camera.zoom -= 1;
	draw(fdf);
}

void	flat(t_fdf *fdf)
{
	fdf->camera.alpha = 0;
	fdf->camera.beta = 0;
	fdf->camera.gamma = 0;
	fdf->iso = 0;
	draw(fdf);
}

void	profile(t_fdf *fdf)
{
	if (!fdf->iso)
		fdf->iso = 1;
	fdf->camera.alpha = -0.34;
	fdf->camera.beta = -0.425;
	draw(fdf);
}

void	return_iso(t_fdf *fdf)
{
	fdf->iso = 1;
	fdf->camera.alpha = 0;
	fdf->camera.beta = 0;
	fdf->camera.gamma = 0;
	fdf->camera.shift_x = fdf->menu.width + 450;
	fdf->camera.shift_y = fdf->win_height / 8;
	fdf->camera.zoom = fdf->win_width / (fdf->matrix.rows * 2);
	fdf->camera.z_divisor = 4;
	draw(fdf);
}
