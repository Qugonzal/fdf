#include "mlx.h"
#include "fdf.h"

void	draw_segment_q1(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	e = x2 - x1;
	dx = 2 * e;
	dy = (y2 - y1) * 2;
	while (x1 <= x2)
	{
		mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, info->color);
		x1++;
		if ((e = e - dy) < 0)
		{
			y1 = y1 + 1;
			e = e + dx;
		}
	}
}

void	draw_segment_q2(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	e = y2 - y1;
	dx = (x2 - x1) * 2;
	dy = 2 * e;
	while (y1 <= y2)
	{
		mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, info->color);
		y1++;
		if ((e = e - dx) < 0)
		{
			x1 = x1 + 1;
			e = e + dy;
		}
	}
}

void	draw_segment_q7(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	e = y2 - y1;
	dx = 2 * (x2 - x1);
	dy = e * 2;
	while (y1 >= y2)
	{
		mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, info->color);
		y1--;
		if ((e = e + dx) > 0)
		{
			x1 = x1 + 1;
			e = e + dy;
		}
	}
}

void	draw_segment_q8(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	e = x2 - x1;
	dx = 2 * e;
	dy = (y2 - y1) * 2;
	while (x1 <= x2)
	{
		mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, info->color);
		x1++;
		if ((e = e + dy) < 0)
		{
			y1 = y1 - 1;
			e = e + dx;
		}
	}
}

void	draw_segment_q4(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	e = x2 - x1;
	dx = 2 * e;
	dy = (y2 - y1) * 2;
	while (x1 >= x2)
	{
		mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, info->color);
		x1--;
		if ((e = e + dy) >= 0)
		{
			y1 = y1 + 1;
			e = e + dx;
		}
	}
}

void	draw_segment_q3(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	e = y2 - y1;
	dx = 2 * (x2 - x1);
	dy = e * 2;
	while (y1 <= y2)
	{
		mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, info->color);
		y1++;
		if ((e = e + dx) <= 0)
		{
			x1 = x1 - 1;
			e = e + dy;
		}
	}
}

void	draw_segment_q5(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	e = x2 - x1;
	dx = 2 * e;
	dy = (y2 - y1) * 2;
	while (x1 >= x2)
	{
		mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, info->color);
		x1--;
		if ((e = e - dy) >= 0)
		{
			y1 = y1 - 1;
			e = e + dx;
		}
	}
}

void	draw_segment_q6(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	e = y2 - y1;
	dx = 2 * (x2 - x1);
	dy = e * 2;
	while (y1 >= y2)
	{
		mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, info->color);
		y1--;
		if ((e = e - dx) >= 0)
		{
			x1 = x1 - 1;
			e = e + dy;
		}
	}
}

void	ft_draw_seg_else(int dy, t_coor *val, t_info *in)
{
	if (dy > 0)
		while (val->y1 <= val->y2)
		{
			mlx_pixel_put(in->mlx_ptr, in->window, val->x1, val->y1, in->color);
			val->y1++;
		}
	else
		while (val->y1 >= val->y2)
		{
			mlx_pixel_put(in->mlx_ptr, in->window, val->x1, val->y1, in->color);
			val->y1--;
		}
}

void	ft_draw_seg_dx_else(int dx, int dy, t_coor *val, t_info *in)
{
	if (dy)
	{
		if (dy > 0)
		{
			if (-dx >= dy)
				draw_segment_q4(val->x1, val->y1, val->x2, val->y2, in);
			else
				draw_segment_q3(val->x1, val->y1, val->x2, val->y2, in);
		}
		else
			if (dx <= dy)
				draw_segment_q5(val->x1, val->y1, val->x2, val->y2, in);
			else
				draw_segment_q6(val->x1, val->y1, val->x2, val->y2, in);
	}
	else
		while (val->x1 >= val->x2)
		{
			mlx_pixel_put(in->mlx_ptr, in->window, val->x1, val->y1, in->color);
			val->x1--;
		}
}

void	ft_draw_seg_dx(int dx, int dy, t_coor *val, t_info *in)
{
	if (dy)
	{
		if (dy > 0)
		{
			if (dx >= dy)
				draw_segment_q1(val->x1, val->y1, val->x2, val->y2, in);
			else
				draw_segment_q2(val->x1, val->y1, val->x2, val->y2, in);
		}
		else
		{
			if (dx >= -dy)
				draw_segment_q8(val->x1, val->y1, val->x2, val->y2, in);
			else
				draw_segment_q7(val->x1, val->y1, val->x2, val->y2, in);
		}
	}
	else
		while (val->x1 <= val->x2)
		{
			mlx_pixel_put(in->mlx_ptr, in->window, val->x1, val->y1, in->color);
			val->x1++;
		}
}

void	draw_seg(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	t_coor val;

	dx = x2 - x1;
	dy = y2 - y1;
	val.x1 = x1;
	val.x2 = x2;
	val.y1 = y1;
	val.y2 = y2;
	if (dx)
	{
		if (dx > 0)
			ft_draw_seg_dx(dx, dy, &val, info);
		else
			ft_draw_seg_dx_else(dx, dy, &val, info);
	}
	else
	{
		ft_draw_seg_else(dy, &val, info);
	}
	mlx_pixel_put(info->mlx_ptr, info->window, x2, y2, info->color);
}
