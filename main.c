#include "include/fdf.h"

void	init_win(t_fdf *fdf, t_map *map)
{
	(void)map;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1300, 800, "FdF");
	mlx_hook(fdf->win, 2, 27, &close_window, fdf);
	mlx_hook(fdf->win, 17, 0, &close_window_with_x, fdf);
}

void	create_plane(t_plane *plane, t_fdf *fdf)
{
	plane->angles[0] = 350;
	plane->angles[1] = 350;
	plane->angles[2] = 600;
	plane->angles[3] = 100;
	plane->angles[4] = 1025;
	plane->angles[5] = 450;
	plane->angles[6] = 775;
	plane->angles[7] = 725;
	draw_plane(plane, fdf);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_fdf	fdf;
	t_plane	plane;

	if (argc != 2)
		die("Usage: ./fdf [map_to_be_read]");
	init_map(argv[1], &map);
	init_win(&fdf, &map);
	create_plane(&plane, &fdf);
	mlx_loop(fdf.mlx);
}
