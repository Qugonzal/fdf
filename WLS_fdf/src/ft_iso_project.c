#include "../inc/fdf.h"

int		ft_xp(int x, int y, t_info *w)
{
	return(w->x_first + w->xdx * x - w->ydx * y - w->zdx * w->map[y][x]);
}

int		ft_yp(int x, int y, t_info *w)
{
	return(w->y_first + w->ydy * y + w->xdy * x - w->zdy * w->map[y][x]);
}

void	ft_ylines(t_info *w)
{
	int		x;
	int		y;
/*
int		xp1;
	int		xp2;
	int		yp1;
	int		yp2;
	*/

	x = 0;
	while (x < w->x_map_size)
	{
		y = 0;
		while (y < (w->y_map_size - 1))
		{
/*
xp1 = ft_xp(x, y, w);
			xp2 = ft_xp(x, y + 1, w);
			yp1 = ft_yp(x, y, w);
			yp2 = ft_yp(x, y + 1, w);
			if (0 <= xp1 <= WIN_W && 0 <= xp2 <= WIN_W &&
					0 <= yp1 <= WIN_H && 0 <= yp2 <= WIN_H)
				draw_seg(xp1, yp1, xp2, yp2, w);
				*/
			draw_seg(ft_xp(x, y, w), ft_yp(x, y, w),
						ft_xp(x, y + 1, w), ft_yp(x, y + 1, w), w);
			y++;
		}
		x++;
	}
}

void	ft_xlines(t_info *w)
{
	int		x;
	int		y;
/*
int		xp1;
	int		xp2;
	int		yp1;
	int		yp2;
	*/

	y = 0;
	while (y < w->y_map_size)
	{
		x = 0;
		while (x < (w->x_map_size - 1))
		{
/*
xp1 = ft_xp(x, y, w);
			xp2 = ft_xp(x + 1, y, w);
			yp1 = ft_yp(x, y, w);
			yp2 = ft_yp(x + 1, y, w);
			if (0 <= xp1 <= WIN_W && 0 <= xp2 <= WIN_W &&
					0 <= yp1 <= WIN_H && 0 <= yp2 <= WIN_H)
				draw_seg(xp1, yp1, xp2, yp2, w);
				*/
		draw_seg(ft_xp(x, y, w), ft_yp(x, y, w),
						ft_xp(x + 1, y, w), ft_yp(x + 1, y, w), w);
			x++;
		}
		y++;
	}
}

void	ft_para_project(t_info *w)
{
	if (w->projection == 3)
	{
		w->dd->angle_x = 0.0;
		w->dd->angle_y = 0.0;
		w->dd->angle_z = 45.0;
		w->projection = 4;
	}
	w->xdx = cos((w->dd->angle_x) * (w->dd->pi)) * w->zoom;
	w->xdy = sin((w->dd->angle_x) * (w->dd->pi)) * w->zoom;
	w->ydx = sin((w->dd->angle_y) * (w->dd->pi)) * w->zoom;
	w->ydy = cos((w->dd->angle_y) * (w->dd->pi)) * w->zoom;
	if (!(w->zdx))
		if (!(w->zdx = sin((w->dd->angle_z) * (w->dd->pi)) * w->zoom / 10))
			w->zdx = 1;
	if (!(w->zdy))
		if (!(w->zdy = cos((w->dd->angle_z) * (w->dd->pi)) * w->zoom / 10))
			w->zdy = 1;
	ft_xlines(w);
	ft_ylines(w);
}

void	ft_iso_project(t_info *w)
{
	if (w->projection == 0)
	{
		w->dd->angle_x = 0.0;
		w->dd->angle_y = 30.0;
		w->dd->angle_z = 30.0;
		w->projection = 1;
	}
	w->xdx = cos((w->dd->angle_x) * (w->dd->pi)) * w->zoom;
	w->xdy = sin((w->dd->angle_x) * (w->dd->pi)) * w->zoom;
	w->ydx = sin((w->dd->angle_y) * (w->dd->pi)) * w->zoom;
	w->ydy = cos((w->dd->angle_y) * (w->dd->pi)) * w->zoom;
	if (!(w->zdx))
		if (!(w->zdx = sin((w->dd->angle_z) * (w->dd->pi)) * w->zoom / 10))
			w->zdx = 1;
	if (!(w->zdy))
		if (!(w->zdy = cos((w->dd->angle_z) * (w->dd->pi)) * w->zoom / 10))
			w->zdy = 1;
	ft_xlines(w);
	ft_ylines(w);
}
