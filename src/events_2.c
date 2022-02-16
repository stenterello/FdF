#include "fdf.h"

void	rotate_x(float *y, int *z, double alpha)
{
    int prev_y;

    prev_y = *y;
    *y = prev_y * cos(alpha) + *z * sin(alpha);
    *z = -prev_y * sin(alpha) + *z * cos(alpha);
}

// static void	rotate_y(t_fdf *fdf)
// {

// }

// static void	rotate_z(t_fdf *fdf)
// {

// }



int mouse_move(void *param)
{
    t_fdf   *fdf;

    fdf = (t_fdf *)param;
    if (fdf->mouse.is_pressed)
    {
        fdf->alpha += 1;
        fdf->mouse.prev_x = fdf->mouse.x;
        fdf->mouse.prev_y = fdf->mouse.y;
    }
    return (0);
}

int	mouse_press(int keycode, int x, int y, void *param)
{
    (t_fdf*);
    if (keycode == 1)
        fdf->mouse.is_pressed = 1;
    fdf->alpha += 1;
    fdf->mouse.prev_x = x;
    fdf->mouse.prev_y = y;
    fdf->mouse.is_pressed = 1;
	printf("x: %d\ny: %d\n", x, y);
    mouse_move(&fdf);
	return (0);
}