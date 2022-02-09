#include "include/fdf.h"

void    die(char *str)
{
    ft_putendl_fd(str, 1);
    exit(-1);
}

int check_line(char *line, t_map *map)
{
    char    **ret;
    int     i;
    int     i2;
	int		prev_len;

    i = 0;
    i2 = 0;
    ret = ft_split(line, ' ');
	prev_len = ft_strlen(ret[i]);
    while (ret[i] != NULL)
    {
        while (ret[i][i2] != '\0')
    	{
    		if (!ft_isdigit(ret[i][i2]) && ret[i][i2] != 43 && ret[i][i2] != 45 && ret[i][i2] != '\n')
				die("File text error");
			printf("%c\n", ret[i][i2]);
			i2++;
		}
		i2 = 0;
		map->coord[i] = ft_atoi(ret[i]);
		i++;
    }
	return (1);
}

void    read_check_fill(char *file_name, t_map *map)
{
    int     fd;
    int     ok;
	int		i;
    char    *line;

	line = "a";
    fd = open(file_name, O_RDONLY);
	if (fd < 1)
		die("Read file error");
	i = 0;
	while (line != 0)
	{
    	line = get_next_line(fd);
    	ok = check_line(line, map);
	}
    
}

void    init_map(char *file_name, t_map *map)
{
    read_check_fill(file_name, map);
}

int main(int argc, char **argv)
{
    t_map   *map;

	map = NULL;
    if (argc != 2)
        die("Usage: ./fdf [map_to_be_read]");
    init_map(argv[1], map);
}