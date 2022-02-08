#include <mlx.h>
#include <math.h>
#include <unistd.h>

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

int main(void)
{
    void    *mlx;
    void    *win;
    t_data  img;
    int     i;
    int     i2;

    i = 0;
    i2 = 0;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 400, 300, "FdF");
    img.img = mlx_new_image(mlx, 200, 200);
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
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);
    mlx_loop(mlx);
}