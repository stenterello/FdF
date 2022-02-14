#include "fdf.h"

void	open_win(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		die("Mlx error");
	fdf->win = mlx_new_window(fdf->mlx, 1000, 900, "FdF");
}
