/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment_5_to_8.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:04:25 by quegonza          #+#    #+#             */
/*   Updated: 2020/05/02 19:05:15 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_segment_q5(t_info *info)
{
	int dx;
	int dy;
	int e;
	int	x1;
	int	y1;

	x1 = info->x1;
	y1 = info->y1;
	e = info->x2 - x1;
	dx = 2 * e;
	dy = (info->y2 - y1) * 2;
	while (x1 >= info->x2)
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

void	draw_segment_q6(t_info *info)
{
	int dx;
	int dy;
	int e;
	int	x1;
	int	y1;

	x1 = info->x1;
	y1 = info->y1;
	e = info->y2 - y1;
	dx = 2 * (info->x2 - x1);
	dy = e * 2;
	while (y1 >= info->y2)
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

void	draw_segment_q7(t_info *info)
{
	int dx;
	int dy;
	int e;
	int	x1;
	int	y1;

	x1 = info->x1;
	y1 = info->y1;
	e = info->y2 - y1;
	dx = 2 * (info->x2 - x1);
	dy = e * 2;
	while (y1 >= info->y2)
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

void	draw_segment_q8(t_info *info)
{
	int dx;
	int dy;
	int e;
	int	x1;
	int	y1;

	x1 = info->x1;
	y1 = info->y1;
	e = info->x2 - x1;
	dx = 2 * e;
	dy = (info->y2 - y1) * 2;
	while (x1 <= info->x2)
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
