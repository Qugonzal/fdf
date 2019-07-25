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

#include "mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <X11/Xlib.h>

int		key_press(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		write(1, "SPACE\n", 6);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	ft_putnbr(x);
	ft_putstr("  ");
	ft_putnbr(y);
	ft_putstr("\n");
	return (0);
}

int		x_close(void *param)
{
	(void)param;
	exit(0);
}

int		main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*window;
	void	*param;
	int		x;

	param = 0;
	x = 199;
	if ((mlx_ptr = mlx_init()) == NULL)
		ft_putstr("init fail\n");
	window = mlx_new_window(mlx_ptr, 500, 500, "<<< it's a TITLE >>>");
//	while (++x < 300)
//		mlx_pixel_put(mlx_ptr, window, x, 250, 0xFFFFFF);
//	mlx_hook(window, 2, 0, key_press, param);
//	mlx_hook(window, 17, 0, x_close, param);
//	mlx_hook(window, 6, 0, mouse_move, param);
	mlx_loop(mlx_ptr);
	return (0);
}
