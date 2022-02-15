#include "fdf.h"

static void move_left(t_fdf *fdf)
{
    fdf->shift_x -= 5;
    mlx_clear_window(fdf->mlx, fdf->win);
    draw(fdf);
}

static void move_right(t_fdf *fdf)
{
    fdf->shift_x += 5;
    mlx_clear_window(fdf->mlx, fdf->win);
    draw(fdf);
}

static void move_up(t_fdf *fdf)
{
    fdf->shift_y -= 5;
    mlx_clear_window(fdf->mlx, fdf->win);
    draw(fdf);
}

static void move_down(t_fdf *fdf)
{
    fdf->shift_y += 5;
    mlx_clear_window(fdf->mlx, fdf->win);
    draw(fdf);
}

static void increment_zoom(t_fdf *fdf)
{
    fdf->zoom += 5;
    mlx_clear_window(fdf->mlx, fdf->win);
    draw(fdf);
    fdf->mouse.is_scrolling = 0;
}

static void decrement_zoom(t_fdf *fdf)
{
    fdf->zoom -= 5;
    mlx_clear_window(fdf->mlx, fdf->win);
    draw(fdf);
    fdf->mouse.is_scrolling = 0;
}

static int events(int keycode, t_fdf *fdf)
{
    if (keycode == 53)
    {
        free_matrix(fdf);
        mlx_destroy_window(fdf->mlx, fdf->win);
        exit(0);
    }
    else if (keycode == 0)
        move_left(fdf);
    else if (keycode == 2)
        move_right(fdf);
    else if (keycode == 13)
        move_up(fdf);
    else if (keycode == 1)
        move_down(fdf);
    else if (keycode == 116)
        increment_zoom(fdf);
    else if (keycode == 121)
        decrement_zoom(fdf);
    return (0);
}

static int mouse(int keycode, t_fdf *fdf)
{
    printf("%d\n", keycode);
    printf("OK: %d\n", fdf->mouse.is_scrolling);
    if (keycode == 4 && fdf->mouse.is_scrolling == 0)
    {
        fdf->mouse.is_scrolling = 1;
        decrement_zoom(fdf);
    }
    else if (keycode == 5 && fdf->mouse.is_scrolling == 0)
    {
        fdf->mouse.is_scrolling = 1;
        increment_zoom(fdf);
    }
    
    return (0);
}

void	add_events(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, events, fdf);
    mlx_hook(fdf->win, 4, 0, mouse, &fdf);
    printf("OK: %d\n", fdf->mouse.is_pressed);
}
