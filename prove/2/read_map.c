#include "include/fdf.h"

void	checks(char *file_name, t_map *map)
{
	int		fd;
	int		bytes;
	char	*line;
	char	*buff;

	fd = open(file_name, O_RDONLY);
	bytes = 1;
	buff = ft_calloc(2, sizeof(char));
	line = ft_calloc(2, sizeof(char));
	buff[1] = '\0';
	while (bytes > 0)
	{
		bytes = read(fd, buff, 1);
		line = ft_strjoin_plus(line, buff);
	}
	one_by_one(line, map);
	check_characters(line, map);
	fill_matrix(map, line);
	free(buff);
	free(line);
	close(fd);
}

void	init_map(char *file_name, t_map *map)
{
	checks(file_name, map);
}
