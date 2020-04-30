/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:04:34 by quegonza          #+#    #+#             */
/*   Updated: 2020/04/30 03:52:31 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_para_project(t_info *w)
{
	if (w->projection == 3)
	{
		w->angle_x = 0.0;
		w->angle_y = 0.0;
		w->angle_z = 45.0;
		w->zdim = 10;
		w->projection = 4;
	}
	w->xdx = cos((w->angle_x) * (w->pi)) * w->zoom;
	w->xdy = sin((w->angle_x) * (w->pi)) * w->zoom;
	w->ydx = sin((w->angle_y) * (w->pi)) * w->zoom;
	w->ydy = cos((w->angle_y) * (w->pi)) * w->zoom;
	if (!(w->zdx = sin((w->angle_z) * (w->pi)) * (w->zoom / w->zdim)))
		w->zdx = 1;
	if (!(w->zdy = cos((w->angle_z) * (w->pi)) * (w->zoom / w->zdim)))
		w->zdy = 1;
	ft_xlines(w);
	ft_ylines(w);
}

void	ft_iso_project(t_info *w)
{
	if (w->projection == 0)
	{
		w->angle_x = 0.0;
		w->angle_y = 30.0;
		w->angle_z = 30.0;
		w->zdim = 10;
		w->projection = 1;
	}
	w->xdx = cos((w->angle_x) * (w->pi)) * w->zoom;
	w->xdy = sin((w->angle_x) * (w->pi)) * w->zoom;
	w->ydx = sin((w->angle_y) * (w->pi)) * w->zoom;
	w->ydy = cos((w->angle_y) * (w->pi)) * w->zoom;
	if (!(w->zdx = sin((w->angle_z) * (w->pi)) * (w->zoom / w->zdim)))
		w->zdx = 1;
	if (!(w->zdy = cos((w->angle_z) * (w->pi)) * (w->zoom / w->zdim)))
		w->zdy = 1;
	ft_xlines(w);
	ft_ylines(w);
}
