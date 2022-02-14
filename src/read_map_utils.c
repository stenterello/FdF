#include "fdf.h"

void	fill_line(int *matrix, char *line)
{
	int		i;
	char	**nums;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		matrix[i] = ft_atoi(nums[i]);
		i++;
	}
}

void	init_fdf(t_fdf *fdf)
{
	fdf->win_width = 1000;
	fdf->win_height = 900;
	fdf->shift_x = 350;
	fdf->shift_y = 50;
	fdf->zoom = 20;
}
