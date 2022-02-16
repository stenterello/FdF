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
