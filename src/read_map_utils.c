/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:09:53 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/12 18:09:55 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_line(int *matrix, char *line)
{
	int		i;
	int		len;
	char	**nums;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		matrix[i] = ft_atoi(nums[i]);
		i++;
	}
	len = i + 1;
	i = 0;
	while (i < len)
		free(nums[i++]);
	free(nums);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->win_width = 1600;
	fdf->win_height = 1000;
	fdf->menu.width = 300;
	fdf->menu.height = fdf->win_height;
	fdf->menu.color = 0x00000000;
	fdf->scale_z = 1;
	fdf->iso = 1;
	fdf->start_color = 0x00FF0000;
	fdf->end_color = 0x0000FF00;
}

void	init_camera(t_fdf *fdf)
{
	fdf->camera.alpha = 0;
	fdf->camera.beta = 0;
	fdf->camera.gamma = 0;
	fdf->camera.shift_x = fdf->menu.width + 450;
	fdf->camera.shift_y = fdf->win_height / 8;
	fdf->camera.zoom = fdf->win_width / (fdf->matrix.rows * 2);
	fdf->camera.z_divisor = 4;
}

void	init_mouse(t_fdf *fdf)
{
	fdf->mouse.is_pressed = 0;
	fdf->mouse.prev_x = 0;
	fdf->mouse.prev_y = 0;
	fdf->mouse.x = 0;
	fdf->mouse.y = 0;
}
