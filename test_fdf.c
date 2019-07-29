/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:39:06 by quegonza          #+#    #+#             */
/*   Updated: 2019/07/29 18:17:16 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_info
{
	void	*mlx_ptr;
	void	*window;
}		t_info;

void	raytracer_q1(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	e = x2 - x1;
	dx = 2 * e;
	dy = (y2 - y1) * 2;
	while (x1 <= x2)
	{
		mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, 0xFFFFFF);
		x1++;
		if ((e = e - dy) <= 0)
		{
			y1 = y1 + 1;
			e = e + dx;
		}
	}
	mlx_pixel_put(info->mlx_ptr, info->window, x2, y2, 0xFF0000);
}

void	raytracer_q2(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	e = x2 - x1;
	dx = 2 * e;
	dy = (y2 - y1) * 2;
	while (y1 <= y2)
	{
		mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, 0xFFFFFF);
		x1++;
		if ((e = e - dy) <= 0)
		{
			y1 = y1 + 1;
			e = e + dx;
		}
	}
	mlx_pixel_put(info->mlx_ptr, info->window, x2, y2, 0xFF0000);
}

void	raytracer_q7(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	e = x2 - x1;
	dx = 2 * e;
	dy = (y2 - y1) * 2;
	while (y1 <= y2)
	{
		mlx_pixel_put(info->mlx_ptr, info->window, x1, y1, 0xFFFFFF);
		x1++;
		if ((e = e - dy) <= 0)
		{
			y1 = y1 + 1;
			e = e + dx;
		}
	}
	mlx_pixel_put(info->mlx_ptr, info->window, x2, y2, 0xFF0000);
}

void	raytracer(int x1, int y1, int x2, int y2, t_info *info)
{
	int dx;
	int dy;
	int e;

	if ((dx = x2 - x1) != 0)
	{
		if (dx > 0)
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
						raytracer_q1(x1, y1, x2, y2, info);
					else
						raytracer_q2(x1, y1, x2, y2, info);
				}
			}
		}
	}
}

int		key_press(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		write(1, "SPACE\n", 6);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_info *info;

	info = param;
	mlx_pixel_put(info->mlx_ptr, info->window, x, y, 0xFFFFFF);
	return (0);
}

int		x_close(void *param)
{
	(void)param;
	exit(0);
}

int		main(int ac, char **av)
{
	t_info	info;
	int		x;

	x = 199;
	info.mlx_ptr = mlx_init();
	info.window = mlx_new_window(info.mlx_ptr, 500, 500, "FDF");
	while (++x < 300)
		mlx_pixel_put(info.mlx_ptr, info.window, x, 250, 0xFFFFFF);
	raytracer(50, 50, 80, 50, &info);
	raytracer(50, 50, 80, 80, &info);
	raytracer(50, 50, 80, 20, &info);
	mlx_hook(info.window, 2, 0, key_press, &info);
	mlx_hook(info.window, 17, 0, x_close, &info);
	mlx_hook(info.window, 6, 0, mouse_move, &info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
