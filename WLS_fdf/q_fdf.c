/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_fdf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:39:06 by quegonza          #+#    #+#             */
/*   Updated: 2019/07/23 21:26:05 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <X11/Xlib.h>

void	ft_draw_square(int x, int y, int size, int color, t_info *info)
{
	int x_t;
	int y_t;
	int s;

	x_t = x - 1;
	y_t = y - 1;
	s = x + size;
	while (++x_t <= s)
		mlx_pixel_put(info->mlx_ptr, info->window, x_t, y_t, color);
	s = y + size;
	x_t--;
	while (++y_t <= s)
		mlx_pixel_put(info->mlx_ptr, info->window, x_t, y_t, color);
	y_t--;
	while (--x_t >= x)
		mlx_pixel_put(info->mlx_ptr, info->window, x_t, y_t, color);
	x_t++;
	while (--y_t >= y)
		mlx_pixel_put(info->mlx_ptr, info->window, x_t, y_t, color);
}

void	ft_display_coolstar(int x, int y, t_info *info)
{
	draw_segment(x, y, x, y - 40, info);
	draw_segment(x, y, x + 20, y - 40, info);
	draw_segment(x, y, x + 40, y - 40, info);
	draw_segment(x, y, x + 40, y - 20, info);
	draw_segment(x, y, x + 40, y, info);
	draw_segment(x, y, x + 40, y + 20, info);
	draw_segment(x, y, x + 40, y + 40, info);
	draw_segment(x, y, x + 20, y + 40, info);
	draw_segment(x, y, x, y + 40, info);
	draw_segment(x, y, x - 20, y + 40, info);
	draw_segment(x, y, x - 40, y + 40, info);
	draw_segment(x, y, x - 40, y + 20, info);
	draw_segment(x, y, x - 40, y, info);
	draw_segment(x, y, x - 40, y - 20, info);
	draw_segment(x, y, x - 40, y - 40, info);
	draw_segment(x, y, x - 20, y - 40, info);
}

int		mouse_move(int button, int x, int y, void *param)
{
	ft_putnbr(x);
	ft_putstr("  ");
	ft_putnbr(y);
	ft_putstr("\n");
	return (0);
}

int		keypress(int keycode, void *ptr_info)
{
	t_info	*info;
	info = ptr_info;
	ft_putstr("<((!))> Keycode: ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 65307)
	{
		ft_putstr("\n");
		exit(0);
	}
	if (keycode == 32)
	{
		if (info->color == 0x000000)
		{
			info->color = 0xFFFFFF;
			ft_display_coolstar(50, 50, info);
		}
		else
		{
			info->color = 0x000000;
			ft_display_coolstar(50, 50, info);
		}
		mlx_string_put(info->mlx_ptr,info->window,5,20,0x000000,"String output");
		mlx_string_put(info->mlx_ptr,info->window,15,40,0x00FFFF,"MinilibX test");
	}
	if (keycode == 110)
	{
  		mlx_string_put(info->mlx_ptr,info->window,50,20,0xFF99FF,"String output");
 		mlx_string_put(info->mlx_ptr,info->window,150,40,0x00FFFF,"MinilibX test");
	}
	return (0);
}

/*
int		x_close(void *param)
{
	(void)param;
	exit(0);
}*/

int	mouse_win3(int x, int y, void *info)
{
  ft_putnbr(x);
  ft_putstr("x");
  ft_putnbr(y);
  ft_putstr(" ");
}

//void	qf_square(int x, int y, int dim)

int	main(int ac, char **av)
{
	void	*param;
	t_info	info;
	int		x;

	param = 0;
	x = 199;
	if (!(info.mlx_ptr = mlx_init()))
	{
		ft_putstr("mlx_init returned 0\n");
		exit(1);
	}
	if (!(info.window = mlx_new_window(info.mlx_ptr, 700, 700, "TITLE")))
	{
		ft_putstr("mlx_new_window returned 0\n");
		exit(1);
	}
	while (++x < 300)
		mlx_pixel_put(info.mlx_ptr, info.window, x, 250, 0xFFFFFF);
// 	mlx_hook(info.window, MotionNotify, PointerMotionMask, mouse_win3, 0);
	mlx_key_hook(info.window, keypress, &info);
	mlx_mouse_hook(info.window, mouse_move, &info);
	ft_draw_square(690, 690, 55, 0xFFFFFF, &info);
  	mlx_string_put(info.mlx_ptr,info.window,5,20,0xFF99FF,"String output");
 	mlx_string_put(info.mlx_ptr,info.window,15,40,0x00FFFF,"MinilibX test");
	mlx_loop(info.mlx_ptr);
	return (0);
}
