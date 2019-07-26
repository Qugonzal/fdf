/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:39:06 by quegonza          #+#    #+#             */
/*   Updated: 2019/07/23 21:26:05 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <X11/Xlib.h>

typedef struct	s_info
{
	void	*mlx_ptr;
	void	*window;
}		t_info;

int		mouse_move(int button, int x, int y, void *param)
{
	ft_putnbr(x);
	ft_putstr("  ");
	ft_putnbr(y);
	ft_putstr("\n");
	return (0);
}

int		keypress(int keycode, void *ptr)
{
	t_info	*ptrs;
	ptrs = ptr;
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
  		mlx_string_put(ptrs->mlx_ptr,ptrs->window,5,20,0x000000,"String output");
 		mlx_string_put(ptrs->mlx_ptr,ptrs->window,15,40,0x00FFFF,"MinilibX test");
	}
	if (keycode == 110)
	{
  		mlx_string_put(ptrs->mlx_ptr,ptrs->window,50,20,0xFF99FF,"String output");
 		mlx_string_put(ptrs->mlx_ptr,ptrs->window,150,40,0x00FFFF,"MinilibX test");
	}
	return (0);
}

/*
int		x_close(void *param)
{
	(void)param;
	exit(0);
}*/

int	mouse_win3(int x,int y, void *p)
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
	t_info	ptrs;
	int		x;

	param = 0;
	x = 199;
	if (!(ptrs.mlx_ptr = mlx_init()))
	{
		ft_putstr(" !! KO !!\n");
		exit(1);
	}
	if (!(ptrs.window = mlx_new_window(ptrs.mlx_ptr, 500, 500, "it's a TITLE")))
	{
		ft_putstr(" !! KO !!\n");
		exit(1);
	}
	while (++x < 300)
		mlx_pixel_put(ptrs.mlx_ptr, ptrs.window, x, 250, 0xFFFFFF);
// 	mlx_hook(ptrs.window, MotionNotify, PointerMotionMask, mouse_win3, 0);
	mlx_key_hook(ptrs.window, keypress, &ptrs);
	mlx_mouse_hook(ptrs.window, mouse_move, &ptrs);
  	mlx_string_put(ptrs.mlx_ptr,ptrs.window,5,20,0xFF99FF,"String output");
 	mlx_string_put(ptrs.mlx_ptr,ptrs.window,15,40,0x00FFFF,"MinilibX test");
	mlx_loop(ptrs.mlx_ptr);
	return (0);
}
