/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_tracing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 03:51:06 by quegonza          #+#    #+#             */
/*   Updated: 2020/05/02 19:06:02 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_xp(int x, int y, t_info *w)
{
	return (w->x_first + w->xdx * x - w->ydx * y - w->zdx * w->map[y][x]);
}

int		ft_yp(int x, int y, t_info *w)
{
	return (w->y_first + w->ydy * y + w->xdy * x - w->zdy * w->map[y][x]);
}

void	ft_ylines(t_info *w)
{
	int		x;
	int		y;

	x = 0;
	while (x < w->x_map_size)
	{
		y = 0;
		while (y < (w->y_map_size - 1))
		{
			w->x1 = ft_xp(x, y, w);
			w->x2 = ft_xp(x, y + 1, w);
			w->y1 = ft_yp(x, y, w);
			w->y2 = ft_yp(x, y + 1, w);
			draw_seg(w);
			y++;
		}
		x++;
	}
}

void	ft_xlines(t_info *w)
{
	int		x;
	int		y;

	y = 0;
	while (y < w->y_map_size)
	{
		x = 0;
		while (x < (w->x_map_size - 1))
		{
			w->x1 = ft_xp(x, y, w);
			w->x2 = ft_xp(x + 1, y, w);
			w->y1 = ft_yp(x, y, w);
			w->y2 = ft_yp(x + 1, y, w);
			draw_seg(w);
			x++;
		}
		y++;
	}
}
