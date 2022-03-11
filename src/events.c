#include "fdf.h"

static void	move(t_fdf *fdf, char *str)
{
	if (!ft_strncmp("l", str, 1))
		fdf->camera.shift_x -= 5;
	else if (!ft_strncmp("r", str, 1))
		fdf->camera.shift_x += 5;
	else if (!ft_strncmp("u", str, 1))
		fdf->camera.shift_y -= 5;
	else if (!ft_strncmp("d", str, 1))
		fdf->camera.shift_y += 5;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
}

static void	zoom(t_fdf *fdf, char *str)
{
	if (!ft_strncmp("+", str, 1))
		fdf->camera.zoom += 1;
	else
		fdf->camera.zoom -= 1;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
    menu(fdf);
}

void    change_angle_alpha(t_fdf *fdf, int flag)
{
	if (flag)
	    fdf->camera.alpha += 0.005;
	else
		fdf->camera.alpha += 0.005;
    mlx_clear_window(fdf->mlx, fdf->win);
    draw(fdf);
    menu(fdf);
}

void    change_angle_beta(t_fdf *fdf)
{
    fdf->camera.beta += 0.005;
    mlx_clear_window(fdf->mlx, fdf->win);
    draw(fdf);
    menu(fdf);
}

void    change_angle_gamma(t_fdf *fdf)
{
    fdf->camera.gamma += 0.005;
    mlx_clear_window(fdf->mlx, fdf->win);
    draw(fdf);
    menu(fdf);
}

void    flatten(t_fdf *fdf, int flag)
{
	if (flag && fdf->camera.z_divisor - 0.5 >= 1)
		fdf->camera.z_divisor -= 0.5;
	else if (!flag)
		fdf->camera.z_divisor += 0.5;
    mlx_clear_window(fdf->mlx, fdf->win);
    draw(fdf);
    menu(fdf);
}

// static int	events_linux(int keycode, t_fdf *fdf)
// {
// 	if (keycode == 65307)
// 	{
// 		free_matrix(fdf);
// 		mlx_destroy_window(fdf->mlx, fdf->win);
// 		exit(0);
// 	}
// 	else if (keycode == 97)
// 		move(fdf, "l");
// 	else if (keycode == 100)
// 		move(fdf, "r");
// 	else if (keycode == 119)
// 		move(fdf, "u");
// 	else if (keycode == 115)
// 		move(fdf, "d");
// 	else if (keycode == 65365)
// 		zoom(fdf, "+");
// 	else if (keycode == 65366)
// 		zoom(fdf, "-");
//     else if (keycode == 65436)
//         change_angle_alpha(fdf, 1);
// 	else if (keycode == 65433)
//         change_angle_beta(fdf);
// 	else if (keycode == 65435)
//         change_angle_gamma(fdf);
//     else if (keycode == 46)
//         flatten(fdf, 1);
// 	else if (keycode == 45)
// 		flatten(fdf, 0);
// 	else if (keycode == 113)
// 	{
// 		fdf->iso = 0;
// 		draw(fdf);
// 		menu(fdf);
// 	}
// 	else if (keycode == 111)
// 	{
// 		fdf->camera.alpha = -0.34;
// 		fdf->camera.beta = -0.425;
// 		draw(fdf);
// 		menu(fdf);
// 	}
//     printf("%d\n", keycode);
// 	return (0);
// }

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
    else if (keycode == 83)
        change_angle_alpha(fdf, 1);
	else if (keycode == 84)
        change_angle_beta(fdf);
	else if (keycode == 85)
        change_angle_gamma(fdf);
    else if (keycode == 89)
        flatten(fdf, 1);
	else if (keycode == 92)
		flatten(fdf, 0);
	else if (keycode == 31)
	{
        fdf->camera.alpha = 0;
        fdf->camera.beta = 0;
        fdf->camera.gamma = 0;
		fdf->iso = 0;
		draw(fdf);
		menu(fdf);
	}
	else if (keycode == 35)
	{
        if (!fdf->iso)
            fdf->iso = 1;
		fdf->camera.alpha = -0.34;
		fdf->camera.beta = -0.425;
		draw(fdf);
		menu(fdf);
	}
    else if (keycode == 34)
    {
        fdf->iso = 1;
        draw(fdf);
		menu(fdf);
    }
    else if (keycode == 87)
    {
        
    }
    else if (keycode == 90)
    {
        fdf->camera.gamma -= 0.05;
        draw(fdf);
        menu(fdf);
    }
    else if (keycode == 88)
    {
        fdf->camera.gamma += 0.05;
        draw(fdf);
        menu(fdf);
    }
    printf("%d\n", keycode);
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
	mlx_hook(fdf->win, 2, 1L<<0, events, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
    mlx_hook(fdf->win, 4, 1L<<2, mouse_press, fdf);
	mlx_hook(fdf->win, 6, 1L<<6, mouse_move, fdf);
	mlx_hook(fdf->win, 5, 1L<<3, mouse_release, fdf);
}
