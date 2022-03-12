/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:10:04 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/12 18:10:23 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_win(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		die("Mlx error");
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_width, fdf->win_height, "FdF");
	if (!fdf->win)
		die("Open window error");
}
