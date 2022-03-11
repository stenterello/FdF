#include "fdf.h"

void	fill_line(int *matrix, char *line)
{
	int		i;
	int		len;
	char	**nums;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		matrix[i] = ft_atoi(nums[i]);
		i++;
	}
	len = i + 1;
	i = 0;
	while (i < len)
		free(nums[i++]);
	free(nums);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->win_width = 1300;
	fdf->win_height = 900;
	fdf->menu.width = 300;
	fdf->menu.height = fdf->win_height;
	fdf->menu.color = 0x00000000;
	fdf->scale_z = 1;
	fdf->iso = 1;
}
