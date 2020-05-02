/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:04:32 by quegonza          #+#    #+#             */
/*   Updated: 2020/05/02 19:06:08 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	int	y;

	y = 0;
	while (y < info->y_map_size)
	{
		free(info->map[y]);
		y++;
	}
	free(info->map);
	y = 0;
}

void	ft_draw_projection(t_info *info)
{
	if (info->projection == 3 || info->projection == 4)
	{
		ft_para_project(info);
	}
	if (info->projection == 0 || info->projection == 1)
	{
		ft_iso_project(info);
	}
}

void	ft_init_info(t_info *info)
{
	info->color = 0xFFFFFF;
	info->zoom = WIN_W / info->x_map_size;
	info->zdim = 10;
	info->x_first = WIN_W / info->x_map_size;
	info->y_first = WIN_H / info->y_map_size;
	info->projection = 3;
	info->flag = 0;
	info->xdx = 0;
	info->xdy = 0;
	info->ydx = 0;
	info->ydy = 0;
	info->zdx = 0;
	info->zdy = 0;
	info->pi = PI / 180;
	info->angle_x = 0.0;
	info->angle_y = 0.0;
	info->angle_z = 0.0;
}

int		main(int ac, char **av)
{
	t_info	info;

	if (ac == 2)
	{
		info.x_map_size = 0;
		info.y_map_size = 0;
		if (!ft_parse_input(av[1], &info))
			return (0);
		if (!(info.mlx_ptr = mlx_init()))
		{
			ft_putstr("mlx_init returned 0\n");
			exit(1);
		}
		if (!(info.window = mlx_new_window(info.mlx_ptr, WIN_W, WIN_H, "FdF")))
		{
			ft_putstr("mlx_new_window returned 0\n");
			exit(1);
		}
		ft_init_info(&info);
		ft_draw_projection(&info);
		ft_keypress_help('h', &info);
		mlx_key_hook(info.window, ft_keypress, &info);
		mlx_loop(info.mlx_ptr);
	}
	return (0);
}
