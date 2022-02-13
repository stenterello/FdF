#include "include/fdf.h"

void	free_matrix(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
		free(map->matrix[i++]);
	free(map->matrix);
}

void	alloc_matrix(t_map *map, int width, int height)
{
	int	i;

	i = 0;
	map->width = width;
	map->height = height;
	map->matrix = (int **)ft_calloc(map->height, sizeof(int *));
	while (i < map->height)
	{
		map->matrix[i] = (int *)ft_calloc(map->width, sizeof(int));
		if (!map->matrix[i++])
			return ;
	}
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
			die("Characters error");
		}
		i++;
	}
}

int	count_len(char *text, int *i)
{
	int	nums;

	nums = 0;
	while (text[*i] != '\n')
	{
		if (ft_isdigit(text[*i]) || text[*i] == '-')
		{
			while (ft_isdigit(text[*i]) || text[*i] == '-')
				(*i)++;
			nums++;
		}
		else
			(*i)++;
	}
	(*i)++;
	return (nums);
}

void	one_by_one(char *line, t_map *map)
{
	int	i;
	int	width;
	int	height;
	int	prev_width;

	i = 0;
	height = 0;
	width = 0;
	prev_width = count_len(line, &i);
	while (line[i] != '\0')
	{
		if (line[i] != '\n')
			width = count_len(line, &i);
		else
			i++;
		if (width != prev_width)
			die("Text format error\n");
		else
			height++;
	}
	alloc_matrix(map, width, height);
}
