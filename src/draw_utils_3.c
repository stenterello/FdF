/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:21:04 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/16 19:21:06 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_plane(fdf);
	draw_menu(fdf);
}

int	virtual_bresenham(t_line *line)
{
	int	i;

	i = 0;
	line->virtual_x = line->x;
	line->virtual_y = line->y;
	while (to_continue_virtual(line))
	{
		line->virtual_x += line->d_xy[0];
		line->virtual_y += line->d_xy[1];
		i++;
	}
	return (i);
}

int	to_continue_virtual(t_line *line)
{
	if (get_max_delta(line->d_xy) == ft_abs(line->d_xy[0]))
	{
		if (line->d_xy[0] > 0 && line->virtual_x <= line->dst[0])
			return (1);
		if (line->d_xy[0] < 0 && line->virtual_x >= line->dst[0])
			return (1);
	}
	else if (get_max_delta(line->d_xy) == ft_abs(line->d_xy[1]))
	{
		if (line->d_xy[1] > 0 && line->virtual_y <= line->dst[1])
			return (1);
		if (line->d_xy[1] < 0 && line->virtual_y >= line->dst[1])
			return (1);
	}
	return (0);
}
