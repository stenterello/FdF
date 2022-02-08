#include <mlx.h>
#include <math.h>
#include <unistd.h>

int main()
{
    void    *mlx;
    void    *win;
    void    *img;

    mlx = mlx_init();
    
    win = mlx_new_window(mlx, 400, 300, "FdF");
    img = mlx_new_image(mlx, 200, 200);
    mlx_loop(mlx);
}