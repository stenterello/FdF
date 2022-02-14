#include "fdf.h"

void	die(char *str)
{
	ft_putendl_fd(str, 1);
	exit(-1);
}

static void	free_matrix(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->matrix.matrix[i])
		free(fdf->matrix.matrix[i++]);
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
	mlx_loop(fdf.mlx);
	free_matrix(&fdf);
}
