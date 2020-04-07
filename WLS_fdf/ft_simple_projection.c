#include "fdf.h"

void	ft_simple_ylines(t_info *w)
{
	int		xp;
	int		yp;
	int		x;
	int		y;

	x = 0;
	xp = w->x_first;
	while (x < w->x_map_size)
	{
		y = 0;
		yp = w->y_first - (x * w->angle);
		while (y < (w->y_map_size - 1))
		{
			draw_seg(xp - w->map[y][x], yp - w->map[y][x],
							xp + w->angle - w->map[y + 1][x],
							yp + w->zoom - w->map[y + 1][x], w);
			yp = yp + w->zoom;
			xp = xp + w->angle;
			y++;
		}
		xp = xp + w->zoom - (y * w->angle);
		x++;
	}
}

void	ft_simple_xlines(t_info *w)
{
	int		xp;
	int		yp;
	int		x;
	int		y;

	y = 0;
	yp = w->y_first;
	while (y < w->y_map_size)
	{
		x = 0;
		xp = w->x_first + (y * w->angle);
		while (x < (w->x_map_size - 1))
		{
			draw_seg(xp - w->map[y][x], yp - w->map[y][x],
							xp + w->zoom - w->map[y][x + 1],
							yp - w->angle - w->map[y][x + 1], w);
			xp = xp + w->zoom;
			yp = yp - w->angle;
			x++;
		}
		yp = yp + w->zoom + (x * w->angle);
		y++;
	}
}

void	ft_displaymap_simple(t_info *info)
{
	ft_simple_xlines(info);
	ft_simple_ylines(info);
}
