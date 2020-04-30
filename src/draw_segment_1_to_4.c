/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment_1_to_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:04:12 by quegonza          #+#    #+#             */
/*   Updated: 2020/04/29 19:12:32 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_segment_q1(t_info *info)
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
		if ((e = e - dy) < 0)
		{
			y1 = y1 + 1;
			e = e + dx;
		}
	}
}

void	draw_segment_q2(t_info *info)
{
	int dx;
	int dy;
	int e;
	int	x1;
	int	y1;

	x1 = info->x1;
	y1 = info->y1;
	e = info->y2 - y1;
	dx = (info->x2 - x1) * 2;
	dy = 2 * e;
	while (y1 <= info->y2)
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

void	draw_segment_q3(t_info *info)
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
	while (y1 <= info->y2)
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

void	draw_segment_q4(t_info *info)
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
		if ((e = e + dy) >= 0)
		{
			y1 = y1 + 1;
			e = e + dx;
		}
	}
}
