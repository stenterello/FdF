#include "fdf.h"

double	percentage(int start, int end, int curr)
{
	double	place;
	double	distance;

	place = curr - start;
	distance = end - start;
	if (!distance)
		return (1);
	else
		return (place / distance);
}

int	get_color(int start_color, int end_color, double percent)
{
	return ((int)(1 - percent) * start_color + percent * end_color);
}

int	color_choose(const float xy[2], float dst[2], float d_xy[2])
{
	int		curr[3];
	double	percent;
	int		red;
	int		green;
	int		blue;

	curr[0] = xy[0] + d_xy[0];
	curr[1] = xy[1] + d_xy[1];
	if (d_xy[0] > d_xy[1])
	{
		percent = percentage(xy[0], dst[0], curr[0]);
	}
	else
	{
		percent = percentage(xy[1], dst[1], curr[1]);
	}
	red = get_color((0x00FF0000 >> 12) & 0xFF, (0x0000FF00 >> 16) & 0xFF, percent);
	green = get_color((0x00FF0000 >> 4) & 0xFF, (0x0000FF00 >> 8) & 0xFF, percent);
	blue = get_color(0x00FF0000 & 0xFF, 0x0000FF00 & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}
