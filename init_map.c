#include "include/fdf.h"

int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	while (n > 10)
	{
		i++;
		n /= 10;
	}
	return (++i);
}

int	*get_nums(char *line, t_map *map)
{
	int	i;
	int	i2;
	int	*ret;

	ret = ft_calloc(map->width * map->height, sizeof(int));
	i = 0;
	i2 = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			ret[i2] = ft_atoi(&line[i]);
			i += ft_nbrlen(ret[i2++]);
		}
		i++;
	}
	return (ret);
}

void	fill_matrix(t_map *map, char *line)
{
	int	i;
	int	i2;
	int	i3;
	int	*nums;

	i = 0;
	i3 = 0;
	nums = get_nums(line, map);
	i = 0;
	while (i < map->height)
	{
		i2 = 0;
		while (i2 < map->width)
			map->matrix[i][i2++] = nums[i3++];
		i++;
	}
	free(nums);
}

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
