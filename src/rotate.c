/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:09:57 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/12 18:09:58 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_fdf *fdf, float *y, float *z)
{
	float	prev_y;

	prev_y = *y;
	*y = prev_y * cos(fdf->camera.alpha) + *z * sin(fdf->camera.alpha);
	*z = -prev_y * sin(fdf->camera.alpha) + *z * cos(fdf->camera.alpha);
}

void	rotate_y(t_fdf *fdf, float *x, float *z)
{
	float	prev_x;

	prev_x = *x;
	*x = prev_x * cos(fdf->camera.beta) + *z * sin(fdf->camera.beta);
	*z = -prev_x * sin(fdf->camera.beta) + *z * cos(fdf->camera.beta);
}

void	rotate_z(t_fdf *fdf, float *x, float *y)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(fdf->camera.gamma) + prev_y * sin(fdf->camera.gamma);
	*y = prev_y * sin(fdf->camera.gamma) + prev_y * cos(fdf->camera.gamma);
}

void	rotate(t_line *line, t_fdf *fdf, int flag)
{
	if (!flag)
	{
		rotate_x(fdf, &line->y, &line->z[flag]);
		rotate_y(fdf, &line->x, &line->z[flag]);
		rotate_z(fdf, &line->x, &line->y);
	}
	else
	{
		rotate_x(fdf, &line->dst[1], &line->z[flag]);
		rotate_y(fdf, &line->dst[0], &line->z[flag]);
		rotate_z(fdf, &line->dst[0], &line->dst[1]);
	}
}
