/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:04:28 by quegonza          #+#    #+#             */
/*   Updated: 2020/05/02 19:05:30 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_help_info(int color, int pos_x, int pos_y, t_info *info)
{
	mlx_string_put(info->mlx_ptr, info->window, pos_x, pos_y, color,
			"HELP  = 'h'");
	mlx_string_put(info->mlx_ptr, info->window, pos_x, pos_y + 15, color,
			"LEFT  = 'j' or 'left'");
	mlx_string_put(info->mlx_ptr, info->window, pos_x, pos_y + 15 * 2, color,
			"UP    = 'i' or 'up'");
	mlx_string_put(info->mlx_ptr, info->window, pos_x, pos_y + 15 * 3, color,
			"RIGHT = 'l' or 'right'");
	mlx_string_put(info->mlx_ptr, info->window, pos_x, pos_y + 15 * 4, color,
			"DOWN  = 'k' or 'down'");
	mlx_string_put(info->mlx_ptr, info->window, pos_x, pos_y + 15 * 5, color,
			"DEPTH+ = 'z'");
	mlx_string_put(info->mlx_ptr, info->window, pos_x, pos_y + 15 * 6, color,
			"DEPTH- = 's'");
	mlx_string_put(info->mlx_ptr, info->window, pos_x, pos_y + 15 * 7, color,
			"ROTATE+ = 'e'");
	mlx_string_put(info->mlx_ptr, info->window, pos_x, pos_y + 15 * 8, color,
			"ROTATE- = 'd'");
	mlx_string_put(info->mlx_ptr, info->window, pos_x, pos_y + 15 * 9, color,
			"ZOOM+ = 'r'");
	mlx_string_put(info->mlx_ptr, info->window, pos_x, pos_y + 15 * 10, color,
			"ZOOM- = 'f'");
	mlx_string_put(info->mlx_ptr, info->window, pos_x, pos_y + 15 * 11, color,
			"CHANGE PROJECTION = 'x'");
}

void	ft_keypress_help(int keycode, t_info *info)
{
	int		pos_x;
	int		pos_y;

	pos_x = 5;
	pos_y = 15;
	if (keycode == 'h')
	{
		if (info->flag == 0)
		{
			ft_help_info(0x000000, pos_x - 1, pos_y, info);
			ft_help_info(0x000000, pos_x + 1, pos_y, info);
			ft_help_info(0x000000, pos_x, pos_y - 1, info);
			ft_help_info(0x000000, pos_x, pos_y + 1, info);
			ft_help_info(0x00FF00, pos_x, pos_y, info);
			info->flag = 1;
		}
		else
		{
			ft_help_info(0x000000, pos_x, pos_y, info);
			ft_draw_projection(info);
			info->flag = 0;
		}
	}
}

int		ft_keypress(int keycode, void *ptr)
{
	t_info	*info;

	info = (t_info *)ptr;
	ft_keypress_help(keycode, info);
	if (keycode != 'h')
	{
		ft_keypress_left(keycode, info);
		ft_keypress_up(keycode, info);
		ft_keypress_right(keycode, info);
		ft_keypress_down(keycode, info);
		ft_keypress_rotate(keycode, info);
		ft_keypress_switch(keycode, info);
		ft_keypress_zoom(keycode, info);
		ft_keypress_depth(keycode, info);
		if (info->flag == 1)
			ft_keypress_help('h', info);
	}
	if (keycode == 65307)
	{
		ft_free_map(info);
		exit(0);
	}
	return (0);
}
