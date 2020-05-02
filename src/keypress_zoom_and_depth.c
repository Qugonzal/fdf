/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_zoom_and_depth.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:04:31 by quegonza          #+#    #+#             */
/*   Updated: 2020/05/02 19:05:56 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
** Increase the 'zoom' by increasing the basic unit of each axis.
*/

void	ft_keypress_zoom(int keycode, t_info *info)
{
	if (keycode == 'r')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->zoom++;
		ft_draw_projection(info);
	}
	if (keycode == 'f')
	{
		if (info->zoom > 3)
		{
			info->color = 0x000000;
			ft_draw_projection(info);
			info->color = 0xFFFFFF;
			info->zoom--;
			ft_draw_projection(info);
		}
	}
}

/*
** Increase the 'depth effect' by increasing the relation between the unit of
** z axis and x (or y) axis.
*/

void	ft_keypress_depth(int keycode, t_info *info)
{
	if (keycode == 'z')
	{
		if (info->zdim > 1)
		{
			info->color = 0x000000;
			ft_draw_projection(info);
			info->color = 0xFFFFFF;
			info->zdim -= 1;
			ft_draw_projection(info);
		}
	}
	if (keycode == 's')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->zdim += 1;
		ft_draw_projection(info);
	}
}
