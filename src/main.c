#include "fdf.h"

void	die(char *str)
{
	ft_putendl_fd(str, 1);
	exit(-1);
}

void	free_matrix(t_fdf *fdf)
{
	int	i;

	i = fdf->matrix.rows - 1;
	while (i)
		free(fdf->matrix.matrix[i--]);
	free(fdf->matrix.matrix[i]);
	free(fdf->matrix.matrix);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		die("Usage: ./fdf [map_to_be_read]");
	read_map(argv[1], &fdf);
	open_win(&fdf);
	draw(&fdf);
	add_events(&fdf);
	mlx_loop(fdf.mlx);
	free_matrix(&fdf);
	exit(0);
}
