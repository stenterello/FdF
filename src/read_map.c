#include "fdf.h"

static int	count_cols(char *s, char c)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	words = 0;
	flag = 1;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c && flag == 1)
		{
			words++;
			flag = 0;
		}
		if (*(s + i) == c)
			flag = 1;
		i++;
	}
	return (words);
}

static int	count_rows(int fd)
{
	int		rows;
	char	*line;

	rows = 0;
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		rows++;
	}
	return (rows);
}

static int	**get_matrix(char *file_name, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		**matrix;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		die ("Wrong file name.");
	line = get_next_line(fd);
	fdf->matrix.cols = count_cols(line, ' ');
	free(line);
	fdf->matrix.rows = count_rows(fd);
	matrix = (int **)malloc((fdf->matrix.rows + 1) * sizeof(int *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < fdf->matrix.rows)
	{
		matrix[i] = (int *)malloc((fdf->matrix.cols + 1) * sizeof(int));
		if (!matrix[i++])
			return (NULL);
	}
	close(fd);
	return (matrix);
}

static void	fill_matrix(int **matrix, char *file_name)
{
	int		fd;
	int		i;
	char	*line;
	int		len;

	i = 0;
	fd = open(file_name, O_RDONLY);
	len = count_rows(fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (i < len - 1)
	{
		fill_line(matrix[i], line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	read_map(char *file_name, t_fdf *fdf)
{
	fdf->matrix.matrix = get_matrix(file_name, fdf);
	fill_matrix(fdf->matrix.matrix, file_name);
	init_fdf(fdf);
}
