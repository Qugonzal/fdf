/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:04:33 by quegonza          #+#    #+#             */
/*   Updated: 2020/04/29 18:04:33 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_fill_tab(char *str, t_info *info)
{
	int x;
	int i;
	int y;

	x = 0;
	i = 0;
	y = 0;
	while ((y < info->y_map_size) && str[i])
	{
		while (str[i] == ' ')
			i++;
		info->map[y][x] = ft_atoi(&str[i]);
		x++;
		while ((str[i] != ' ' && str[i] != '\n') && str[i])
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i] == '\n' || !str[i])
		{
			y++;
			x = 0;
			i++;
		}
	}
}

int		ft_str_to_tab(char *str, t_info *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(info->map = (int **)malloc(sizeof(int *) * info->y_map_size)))
	{
		ft_putstr("error: malloc() returned NULL\n");
		return (0);
	}
	while (y < info->y_map_size)
	{
		if (!(info->map[y] = (int *)malloc(sizeof(int) * info->x_map_size)))
		{
			y--;
			while (y != -1)
				free(info->map[y]);
			free(info->map);
			ft_putstr("error: malloc() returned NULL\n");
			return (0);
		}
		y++;
	}
	ft_fill_tab(str, info);
	return (1);
}

int		ft_parse_input(char *file, t_info *info)
{
	char	*str;
	char	**tab_str;

	if (!(str = ft_open_read(file)))
	{
		ft_putstr("FdF: Error while readding file\n");
		return (0);
	}
	if (!ft_check_input(str, info))
	{
		ft_putstr("FdF: Error in file format\n");
		return (0);
	}
	if (!(ft_str_to_tab(str, info)))
	{
		ft_putstr("FdF: ft_str_to_tab returned 0\n");
		return (0);
	}
	free(str);
	return (1);
}
