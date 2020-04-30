#include "../inc/fdf.h"

void	ft_display_coolstar(int x, int y, t_info *info)
{
	draw_seg(x, y, x, y - 40, info);
	draw_seg(x, y, x + 20, y - 40, info);
	draw_seg(x, y, x + 40, y - 40, info);
	draw_seg(x, y, x + 40, y - 20, info);
	draw_seg(x, y, x + 40, y, info);
	draw_seg(x, y, x + 40, y + 20, info);
	draw_seg(x, y, x + 40, y + 40, info);
	draw_seg(x, y, x + 20, y + 40, info);
	draw_seg(x, y, x, y + 40, info);
	draw_seg(x, y, x - 20, y + 40, info);
	draw_seg(x, y, x - 40, y + 40, info);
	draw_seg(x, y, x - 40, y + 20, info);
	draw_seg(x, y, x - 40, y, info);
	draw_seg(x, y, x - 40, y - 20, info);
	draw_seg(x, y, x - 40, y - 40, info);
	draw_seg(x, y, x - 20, y - 40, info);
}

int		ft_hexadigit(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	if ('A' <= c && c <= 'F')
		return (c - 'A' + 10);
	if ('a' <= c && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

int		ft_alphex_to_int(char *str)
{
	int i;
	int res;

	i = 3;
	res = 0;
	while (str[i] && ft_hexadigit(str[i]) != -1)
	{
		res *= 16;
		res += ft_hexadigit(str[i]);
		i++;
	}
	return (res);
}

void	ft_fill_colors(char **tab_str, t_info *info, int y)
{
	int x;

	if (info->colors)
	{
		if (!(info->colors[y] = (int *)malloc(sizeof(int) * info->x_map_size)))
			ft_error("malloc", 0);
		x = 0;
		while (tab_str[x])
		{
			if (ft_strstr(tab_str[x], ",0x"))
				info->colors[y][x] = ft_alphex_to_int(ft_strchr(tab_str[x], ','));
			x++;
		}
	}
}
