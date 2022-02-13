#include "include/fdf.h"

void	die(char *str)
{
	ft_putendl_fd(str, 1);
	exit(-1);
}

int	close_window(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	return (0);
}

int	close_window_with_x(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
	return (0);
}

int	ft_power(int base, int esp)
{
	int	i;
	int	ret;

	i = 1;
	while (i++ < esp)
		ret *= base;
	return (ret);
}

int	ft_sqrt(int c)
{

}
