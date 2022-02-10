#include "include/fdf.h"

void    die(char *str)
{
    ft_putendl_fd(str, 1);
    exit(-1);
}

int main(int argc, char **argv)
{
    t_map   *map;

	map = NULL;
    if (argc != 2)
        die("Usage: ./fdf [map_to_be_read]");
    init_map(argv[1], map);
}