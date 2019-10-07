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

void	draw_segment(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx)
	{
		if (dx > 0)
		{
			if (dy)
			{
				if (dy > 0)
				{
					if (dx >= dy)
						draw_segment_q1(x1, y1, x2, y2, info);
					else
						draw_segment_q2(x1, y1, x2, y2, info);
				}
				else
				{
					if (dx >= -dy)
						draw_segment_q8(x1, y1, x2, y2, info);
					else
						draw_segment_q7(x1, y1, x2, y2, info);
				}
			}
			else
				while (x1 <= x2)
				{
					mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, info->color);
					x1++;
				}
		}
		else
		{
			if (dy)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
						draw_segment_q4(x1, y1, x2, y2, info);
					else
						draw_segment_q3(x1, y1, x2, y2, info);
				}
				else
					if (dx <= dy)
						draw_segment_q5(x1, y1, x2, y2, info);
					else
						draw_segment_q6(x1, y1, x2, y2, info);
			}
			else
				while (x1 >= x2)
				{
					mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, info->color);
					x1--;
				}
		}
	}
	else
	{
		if (dy > 0)
				while (y1 <= y2)
			{
				mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, info->color);
				y1++;
			}
		else
			while (y1 >= y2)
			{
				mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, info->color);
				y1--;
			}
	}
	mlx_pixel_put(info->mlx_ptr, info->window, x2, y2, info->color);
}
