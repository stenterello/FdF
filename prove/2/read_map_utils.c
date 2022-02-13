#include "include/fdf.h"

int	count_len(int width, char *text)
{
	int	i;
	int	nums;

	i = 0;
	nums = 0;
	while (i < width)
	{
		if (ft_isdigit(text[i]) || text[i] == '-')
		{
			while (ft_isdigit(text[i]) || text[i] == '-')
				i++;
			nums++;
		}
		else
			i++;
	}
	return (nums);
}

void	alloc_matrix(t_map *map, int width, int height)
{
	int	i;

	i = 0;
	map->width = width;
	map->height = height;
	map->matrix = ft_calloc(map->height, sizeof(int *));
	if (!*map->matrix)
		return ;
	while (i < map->width)
	{
		map->matrix[i] = ft_calloc(1, sizeof(int));
		if (!*map->matrix[i++])
			return ;
	}
}

void	one_by_one(char *line, t_map *map)
{
	int	i;
	int	i2;
	int	len;
	int	prev_len;

	i = 0;
	i2 = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			i++;
			len = i - (len * i2);
			if (len != prev_len && i2 > 0 && len != 1)
				die("Text format error");
			else if (len != 1)
				prev_len = len;
			i2++;
		}
		else
			i++;
	}
	alloc_matrix(map, count_len(prev_len, line), --i2);
}

void	free_matrix(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
		free(map->matrix[i++]);
	free(map->matrix);
}

void	check_characters(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_isdigit(line[i]) && line[i] != 32 && line[i] != 43
			&& line[i] != 45 && line[i] != '\n')
		{
			free_matrix(map);
			die("Text format error");
		}
		i++;
	}
}
