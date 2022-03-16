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
	if (keycode == 116)
		fdf->camera.zoom += 1;
	else
		fdf->camera.zoom -= 1;
	draw(fdf);
}
