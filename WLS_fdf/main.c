#include <mlx.h>
#include "fdf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <fcntl.h>

void	ft_displaymap_simple(t_info *info);

char 	*ft_read(int fd)
{
	int		i;
	char	buf[2];
	char	*tmp;
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) *  + 1)))
	{
		ft_putstr("malloc returned NULL\n");
		exit(-1);
	}
	ft_bzero(str, 2);
	i = 0;
	while ((i = read(fd, buf, 1)))
	{
		if (i == -1)
		{
			ft_putstr("read returned -1\n");
			exit(-1);
		}
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	return (str);
}

char	*ft_open_read(char *file)
{
	int		fd;
	char	*str;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("open returned -1\n");
		exit(-1);
	}
	str = ft_read(fd);
	close(fd);
	return (str);
}

int		*ft_nb_strsplit(char *str, t_info *info)
{
	char	**tab_str;
	int		*tab;
	int		x;

	if (!(tab_str = ft_strsplit(str, ' ')))
	{
		free(str);
		exit(-1);
	}
	free(str);
	x = 0;
	while (tab_str[x])
		x++;
	info->x_map_size = x;
	if (!(tab = (int *)malloc(sizeof(int) * x - 1)))
	{
		ft_putstr("malloc returned NULL\n");
		exit(-1);
	}
	x = 0;
	while (tab_str[x])
	{
		tab[x] = ft_atoi(tab_str[x]);
		free(tab_str[x]);
		x++;
	}
	free(tab_str[x]);
	return (tab);
}

int		**ft_parse_input(char *file, t_info *info)
{
	int		**map;
	int		y;
	int		x;
	char	*str;
	char	**tab_str;

	str = ft_open_read(file);
	if (!(tab_str = ft_strsplit(str, '\n')))
	{
		free(str);
		exit(-1);
	}
	free(str);
	y = 0;
	while (tab_str[y])
		y++;
	info->y_map_size = y;
	if (!(map = (int **)malloc(sizeof(int *) * y - 1)))
	{
		ft_putstr("malloc returned NULL\n");
		exit(-1);
	}
	y = 0;
	while (y < info->y_map_size)
	{
		if (!(map[y] = ft_nb_strsplit(tab_str[y], info)))
		{
			while (--y >= 0)
				free(map[y]);
			while (y <= info->y_map_size)
				free(tab_str[y]);
			ft_putstr("ft_strsplit_atoi returned NULL\n");
			exit(-1);
		}
		y++;
	}
	return (map);
}

void	ft_free_map(int **map, t_info *info)
{
	int 	y;

	y = 0;
	while (y < info->y_map_size)
	{
			free(map[y]);
			y++;
	}
	free(map);
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

int		keypress(int keycode, void *ptr_info)
{
	t_info	*info;
	info = ptr_info;
	ft_putstr("<((!))> Keycode: ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 65307)
	{
		//ft_putstr("\n");
		exit(0);
	}
	if (keycode == ' ')
	{
		if (info->color == 0x000000)
		{
			info->color = 0xFFFFFF;
			ft_display_coolstar(50, 50, info);
			mlx_string_put(info->mlx_ptr,info->window,5,20,info->color,"String output");
			mlx_string_put(info->mlx_ptr,info->window,15,40,info->color,"MinilibX test");
		}
		else
		{
			info->color = info->color;
			ft_display_coolstar(50, 50, info);
			mlx_string_put(info->mlx_ptr,info->window,5,20,info->color,"String output");
			mlx_string_put(info->mlx_ptr,info->window,15,40,info->color,"MinilibX test");
		}
	}
	if (keycode == 65361) // <
	{
		info->color = 0x000000;
		ft_displaymap_simple(info);
		info->color = 0xFFFFFF;
		info->x_first -= 5;
		ft_displaymap_simple(info);
	}
	if (keycode == 65362) // ^
	{
		info->color = 0x000000;
		ft_displaymap_simple(info);
		info->color = 0xFFFFFF;
		info->y_first -= 5;
		ft_displaymap_simple(info);
	}
	if (keycode == 65363) // >
	{
		info->color = 0x000000;
		ft_displaymap_simple(info);
		info->color = 0xFFFFFF;
		info->x_first += 5;
		ft_displaymap_simple(info);
	}
	if (keycode == 65364) // v
	{
		info->color = 0x000000;
		ft_displaymap_simple(info);
		info->color = 0xFFFFFF;
		info->y_first += 5;
		ft_displaymap_simple(info);
	}
	if (keycode == 'p')
	{
		info->color = 0x000000;
		ft_displaymap_simple(info);
		info->color = 0xFFFFFF;
		info->zoom++;
		ft_displaymap_simple(info);
	}
	if (keycode == 'm')
	{
		info->color = 0x000000;
		ft_displaymap_simple(info);
		info->color = 0xFFFFFF;
		info->zoom--;
		ft_displaymap_simple(info);
	}
	if (keycode == 'q')
	{
		info->color = 0x000000;
		ft_displaymap_simple(info);
		info->color = 0xFFFFFF;
	}
	if (keycode == 'm')
	{
  		mlx_string_put(info->mlx_ptr,info->window,50,20,0xFF99FF,"String output");
 		mlx_string_put(info->mlx_ptr,info->window,150,40,0x00FFFF,"MinilibX test");
	}
	return (0);
}

void	ft_displaymap_simple(t_info *info)
{
	int		xp;
	int		yp;
	int		x;
	int		y;

	y = 0;
	yp = info->y_first;
	while (y < info->y_map_size)
	{
		x = 0;
		xp = info->x_first;
		while (x < (info->x_map_size - 1))
		{
//mlx_pixel_put(info->mlx_ptr,info->window,xp-map[y][x],yp-map[y][x],0xFFFFFF);
			draw_segment(xp - info->map[y][x], yp - info->map[y][x], xp + info->zoom - info->map[y][x + 1], yp - info->map[y][x + 1], info);
			//	ft_putnbr(map[y][x]);
			xp = xp + info->zoom;
			x++;
		}
		yp = yp + info->zoom;
		y++;
	}
	x = 0;
	xp = info->x_first;
	while (x < info->x_map_size)
	{
		y = 0;
		yp = info->y_first;
		while (y < (info->y_map_size - 1))
		{
//mlx_pixel_put(info->mlx_ptr,info->window,xp-map[y][x],yp-map[y][x],0xFFFFFF);
			draw_segment(xp - info->map[y][x], yp - info->map[y][x], xp - info->map[y + 1][x], yp + info->zoom - info->map[y + 1][x], info);
			//	ft_putnbr(map[y][x]);
			yp = yp + info->zoom;
			y++;
		}
		xp = xp + info->zoom;
		x++;
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
		info.zoom = 700 / info.x_map_size;
		info.x_first = 700 / info.x_map_size - 10;
		info.y_first = 700 / info.y_map_size - 10;
		ft_displaymap_simple(&info);
		mlx_key_hook(info.window, keypress, &info);
	//	ft_free_map(info.map, &info);
		mlx_loop(info.mlx_ptr);
	}
	return (0);
}
