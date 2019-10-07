/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:21:41 by quegonza          #+#    #+#             */
/*   Updated: 2019/10/07 18:23:40 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *fonction, void *ptr)
{
	ft_putstr(fonction);
	ft_putstr(" error\n");
	if (ptr)
		free(ptr);
	exit(EXIT_FAILURE);
}

void	ft_free_map(t_info *info)
{
	int 	y;

	y = 0;
	while (y < info->y_map_size)
	{
			free(info->map[y]);
			y++;
	}
	free(info->map);
	y = 0;
	while (y < info->y_map_size)
	{
			free(info->colors[y]);
			y++;
	}
	free(info->colors);
}

void	ft_draw_projection(t_info *info)
{
	if (info->projection == 0)
	{
		ft_displaymap_simple(info);
	}
}

int		main(int ac, char **av)
{
	t_info	info;

	if (ac == 2)
	{
		ft_bzero(&info, sizeof(t_info));
		info.map = ft_parse_input(av[1], &info);
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
		ft_putnbr(info.x_map_size);
		ft_putnbr(info.y_map_size);
		info.color = 0xFFFFFF;
		info.angle = 0;
		info.zoom = 700 / info.x_map_size / 2;
		info.x_first = 700 / info.x_map_size * 2;
		info.y_first = 700 / info.y_map_size * 2;
	//	ft_free_map(info.map, &info);
		ft_draw_projection(&info);
		mlx_hook(info.window, 2, 0, keypress, &info);
		mlx_loop(info.mlx_ptr);
	}
	return (0);
}
