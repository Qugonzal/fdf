/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:04:27 by quegonza          #+#    #+#             */
/*   Updated: 2020/04/30 03:39:38 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_draw_seg_dx(int dx, int dy, t_info *in)
{
	if (dy)
	{
		if (dy > 0)
		{
			if (dx >= dy)
				draw_segment_q1(in);
			else
				draw_segment_q2(in);
		}
		else
		{
			if (dx >= -dy)
				draw_segment_q8(in);
			else
				draw_segment_q7(in);
		}
	}
	else
		while (in->x1 <= in->x2)
		{
			mlx_pixel_put(in->mlx_ptr, in->window, in->x1, in->y1, in->color);
			in->x1++;
		}
}

void	ft_draw_seg_dx_else(int dx, int dy, t_info *in)
{
	if (dy)
	{
		if (dy > 0)
		{
			if (-dx >= dy)
				draw_segment_q4(in);
			else
				draw_segment_q3(in);
		}
		else
		{
			if (dx <= dy)
				draw_segment_q5(in);
			else
				draw_segment_q6(in);
		}
	}
	else
		while (in->x1 >= in->x2)
		{
			mlx_pixel_put(in->mlx_ptr, in->window, in->x1, in->y1, in->color);
			in->x1--;
		}
}

void	ft_draw_seg_else(int dy, t_info *in)
{
	if (dy > 0)
		while (in->y1 <= in->y2)
		{
			mlx_pixel_put(in->mlx_ptr, in->window, in->x1, in->y1, in->color);
			in->y1++;
		}
	else
		while (in->y1 >= in->y2)
		{
			mlx_pixel_put(in->mlx_ptr, in->window, in->x1, in->y1, in->color);
			in->y1--;
		}
}

void	draw_seg(t_info *info)
{
	int dx;
	int dy;

	dx = info->x2 - info->x1;
	dy = info->y2 - info->y1;
	if (dx)
	{
		if (dx > 0)
			ft_draw_seg_dx(dx, dy, info);
		else
			ft_draw_seg_dx_else(dx, dy, info);
	}
	else
	{
		ft_draw_seg_else(dy, info);
	}
	mlx_pixel_put(info->mlx_ptr, info->window, info->x2, info->y2, info->color);
}
