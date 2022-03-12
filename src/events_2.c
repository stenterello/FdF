/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:09:38 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/12 18:09:40 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int keycode, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 1)
		fdf->mouse.is_pressed = 1;
	fdf->mouse.prev_x = x;
	fdf->mouse.prev_y = y;
	return (0);
}

void	get_prev(t_fdf *fdf, int x, int y)
{
	fdf->mouse.prev_x = x;
	fdf->mouse.prev_y = y;
}

int	mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;
	int		diff_x;
	int		diff_y;

	fdf = (t_fdf *)param;
	if (!fdf->mouse.prev_x && !fdf->mouse.prev_y)
		get_prev(fdf, x, y);
	if (fdf->mouse.is_pressed)
	{
		diff_x = x - fdf->mouse.prev_x;
		diff_y = y - fdf->mouse.prev_y;
		get_prev(fdf, x, y);
		if (diff_x > 0)
			fdf->camera.beta += 0.005;
		else if (diff_x < 0)
			fdf->camera.beta -= 0.005;
		if (diff_y > 0)
			fdf->camera.alpha += 0.005;
		else if (diff_y < 0)
			fdf->camera.alpha -= 0.005;
		draw(fdf);
	}
	return (0);
}

int	mouse_release(int keycode, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse.is_pressed = 0;
	(void)keycode;
	(void)x;
	(void)y;
	return (0);
}
