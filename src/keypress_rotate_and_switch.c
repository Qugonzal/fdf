/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_rotate_and_switch.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:04:30 by quegonza          #+#    #+#             */
/*   Updated: 2020/04/30 03:47:20 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** Increase or decrease angles of axis
*/

void	ft_keypress_rotate(int keycode, t_info *info)
{
	if (keycode == 'e')
		if (info->angle_z > 0)
		{
			info->color = 0x000000;
			ft_draw_projection(info);
			info->color = 0xFFFFFF;
			info->angle_x += 1.0;
			info->angle_y += 1.0;
			info->angle_z -= 1.0;
			ft_draw_projection(info);
		}
	if (keycode == 'd')
		if (info->angle_z < 90)
		{
			info->color = 0x000000;
			ft_draw_projection(info);
			info->color = 0xFFFFFF;
			info->angle_x -= 1.0;
			info->angle_y -= 1.0;
			info->angle_z += 1.0;
			ft_draw_projection(info);
		}
}

/*
** Change projection type
*/

void	ft_keypress_switch(int keycode, t_info *info)
{
	if (keycode == 'x')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		if (info->projection == 0 || info->projection == 1)
			info->projection = 3;
		else
			info->projection = 0;
		ft_draw_projection(info);
	}
}
