/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:15:01 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/16 19:15:03 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(float c)
{
	if (c < 0)
		return (-c);
	return (c);
}

float	get_max_delta(float ret[3])
{
	if (ft_abs(ret[0]) > ft_abs(ret[1]))
		return (ft_abs(ret[0]));
	return (ft_abs(ret[1]));
}

void	define_delta(t_line *line)
{
	line->d_xy[0] = line->dst[0] - line->x;
	line->d_xy[1] = line->dst[1] - line->y;
	line->d_xy[2] = get_max_delta(line->d_xy);
	line->d_xy[0] /= line->d_xy[2];
	line->d_xy[1] /= line->d_xy[2];
}

int	to_continue(t_line *line)
{
	if (get_max_delta(line->d_xy) == ft_abs(line->d_xy[0]))
	{
		if (line->d_xy[0] > 0 && line->x <= line->dst[0])
			return (1);
		if (line->d_xy[0] < 0 && line->x >= line->dst[0])
			return (1);
	}
	else if (get_max_delta(line->d_xy) == ft_abs(line->d_xy[1]))
	{
		if (line->d_xy[1] > 0 && line->y <= line->dst[1])
			return (1);
		if (line->d_xy[1] < 0 && line->y >= line->dst[1])
			return (1);
	}
	return (0);
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
