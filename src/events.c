#include "fdf.h"

static void	move(t_fdf *fdf, char *str)
{
	if (!ft_strncmp("l", str, 1))
		fdf->shift_x -= 5;
	else if (!ft_strncmp("r", str, 1))
		fdf->shift_x += 5;
	else if (!ft_strncmp("u", str, 1))
		fdf->shift_y -= 5;
	else if (!ft_strncmp("d", str, 1))
		fdf->shift_y += 5;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
}

static void	zoom(t_fdf *fdf, char *str)
{
	if (!ft_strncmp("+", str, 1))
		fdf->zoom += 1;
	else
		fdf->zoom -= 1;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
	fdf->mouse.is_scrolling = 0;
}

static int	events(int keycode, t_fdf *fdf)
{
	if (keycode == 53 || keycode == 17)
	{
		free_matrix(fdf);
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	else if (keycode == 0)
		move(fdf, "l");
	else if (keycode == 2)
		move(fdf, "r");
	else if (keycode == 13)
		move(fdf, "u");
	else if (keycode == 1)
		move(fdf, "d");
	else if (keycode == 116)
		zoom(fdf, "+");
	else if (keycode == 121)
		zoom(fdf, "-");
	return (0);
}

static int	close_window(t_fdf *fdf)
{
	free_matrix(fdf);
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

void	add_events(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, events, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
}
