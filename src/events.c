/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:09:11 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/12 18:09:14 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_window(t_fdf *fdf)
{
	free_matrix(fdf);
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

void	change_angle(t_fdf *fdf, int keycode)
{
	if (keycode == 83)
		fdf->camera.alpha += 0.005;
	else if (keycode == 84)
		fdf->camera.beta += 0.005;
	else if (keycode == 85)
		fdf->camera.gamma += 0.005;
	else if (keycode == 88)
		fdf->camera.gamma -= 0.005;
	draw(fdf);
}

static int	events(int keycode, t_fdf *fdf)
{
	if (keycode == 53 || keycode == 17)
		close_window(fdf);
	else if (keycode >= 0 && keycode <= 13)
		move(fdf, keycode);
	else if (keycode == 116 || keycode == 121)
		zoom(fdf, keycode);
	else if ((keycode >= 83 && keycode <= 85) || keycode == 88)
		change_angle(fdf, keycode);
	else if (keycode == 89 || keycode == 92)
		flatten(fdf, keycode);
	else if (keycode == 31)
	{
		fdf->camera.alpha = 0;
		fdf->camera.beta = 0;
		fdf->camera.gamma = 0;
		fdf->iso = 0;
		draw(fdf);
	}
	else if (keycode == 35)
	{
		if (!fdf->iso)
			fdf->iso = 1;
		fdf->camera.alpha = -0.34;
		fdf->camera.beta = -0.425;
		draw(fdf);
	}
	else if (keycode == 34)
	{
		fdf->iso = 1;
		draw(fdf);
	}
	printf("%d\n", keycode);
	return (0);
}

void	add_events(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 1L << 0, events, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	mlx_hook(fdf->win, 4, 1L << 2, mouse_press, fdf);
	mlx_hook(fdf->win, 6, 1L << 6, mouse_move, fdf);
	mlx_hook(fdf->win, 5, 1L << 3, mouse_release, fdf);
}
