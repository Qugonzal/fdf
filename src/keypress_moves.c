/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:04:29 by quegonza          #+#    #+#             */
/*   Updated: 2020/05/02 19:05:38 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_keypress_left(int keycode, t_info *info)
{
	if (keycode == 'j')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->x_first += 50;
		ft_draw_projection(info);
	}
	if (keycode == 65361)
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->x_first += 5;
		ft_draw_projection(info);
	}
}

void	ft_keypress_up(int keycode, t_info *info)
{
	if (keycode == 'i')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->y_first += 50;
		ft_draw_projection(info);
	}
	if (keycode == 65362)
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->y_first += 5;
		ft_draw_projection(info);
	}
}

void	ft_keypress_right(int keycode, t_info *info)
{
	if (keycode == 'l')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->x_first -= 50;
		ft_draw_projection(info);
	}
	if (keycode == 65363)
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->x_first -= 5;
		ft_draw_projection(info);
	}
}

void	ft_keypress_down(int keycode, t_info *info)
{
	if (keycode == 'k')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->y_first -= 50;
		ft_draw_projection(info);
	}
	if (keycode == 65364)
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->y_first -= 5;
		ft_draw_projection(info);
	}
}
