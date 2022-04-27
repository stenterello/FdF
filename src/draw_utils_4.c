/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:11:30 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/17 20:11:32 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_plane(t_fdf *fdf)
{
	t_line	line;

	draw_background(fdf);
	line.xy[1] = 0;
	while (line.xy[1] < fdf->matrix.rows)
	{
		line.xy[0] = 0;
		while (line.xy[0] < fdf->matrix.cols)
		{
			if (line.xy[0] < fdf->matrix.cols - 1)
				first_draw(&line, fdf);
			if (line.xy[1] < fdf->matrix.rows - 1)
				second_draw(&line, fdf);
			line.xy[0]++;
		}
		line.xy[1]++;
	}
}

void	first_draw(t_line *line, t_fdf *fdf)
{
	line->dst[0] = line->xy[0] + 1;
	line->dst[1] = line->xy[1];
	bresenham(line, fdf);
}

void	second_draw(t_line *line, t_fdf *fdf)
{
	line->dst[0] = line->xy[0];
	line->dst[1] = line->xy[1] + 1;
	bresenham(line, fdf);
}
