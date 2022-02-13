#include <mlx.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct  s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

typedef struct s_vars
{
    void    *mlx;
    void    *win;
}              t_vars;

int close_window(int keycode, t_vars *vars)
{
    printf("%d\n", keycode);
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}

int close_window_with_x(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
    return (0);
}

int print_hi(int button, int x, int y, void *param)
{
    printf("Ciao caro\n");
    printf("x: %d\ny: %d\n", x, y);
    param = 0;
    ft_putnbr_fd(button, 1);
    return (0);
}

int main(void)
{
    t_vars  vars;
    t_data  img;
    int     i;
    int     i2;

    i = 0;
    i2 = 0;
    vars.mlx = mlx_init();
    if (!vars.mlx)
        exit(-1);
    vars.win = mlx_new_window(vars.mlx, 400, 300, "FdF");
    if (!vars.win)
        exit(-1);
    img.img = mlx_new_image(vars.mlx, 200, 200);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (i < 50)
    {
        while (i2 < 50)
        {
            my_mlx_pixel_put(&img, i, i2, 0x00FF0000);
            i2++;
        }
        i2 = 0;
        i++;
    }
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_hook(vars.win, 2, 27, close_window, &vars);
    mlx_hook(vars.win, 17, 0, close_window_with_x, &vars);
    mlx_mouse_hook(vars.win, &print_hi, 0);
    mlx_loop(vars.mlx);
}