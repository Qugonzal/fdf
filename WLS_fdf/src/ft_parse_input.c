#include "../inc/fdf.h"

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

/*
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
*/

char 	*ft_read(int fd)
{
	int		i;
	char	buf[READ_BUFFSIZE + 1];
	char	*tmp;
	char	*str;

	if (!(str = (char *)malloc(sizeof(char))))
	{
		ft_putstr("error: malloc() returned NULL\n");
		return (NULL);
	}
	str[0] = '\0';
	i = 0;
	while ((i = read(fd, buf, READ_BUFFSIZE)))
	{
		if (i == -1)
		{
			ft_putstr("FdF can't read this file: read() returned -1\n");
			free(str);
			return (NULL);
		}
		tmp = str;
		str = ft_strnjoin(str, buf, i);
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
		ft_putstr("FdF can't open this file: open() returned -1\n");
		return (NULL);
	}
	if (!(str = ft_read(fd)))
		return (NULL);
	close(fd);
	return (str);
}

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

int		ft_fill_x_map_size(int xt, t_info *info)
{
	if (!(info->y_map_size))
	{
		return (0);
	}
	if (!xt)
	{
		return (0);
	}
	info->x_map_size = xt;
	return (1);
}

int		ft_check_input_loop(int *i1, int *xt, char *str, t_info *info)
{
	int i;

	i = *i1;
	if (('9' < str[i] || str[i] < '0') && str[i] != '\n')
		return (ft_fill_x_map_size(*xt, info));
	if ('0' <= str[i] && str[i] <= '9')
	{
		info->x_map_size++;
		while ((str[i] != ' ' && str[i] != '\n') && str[i])
			i++;
	}
	if (str[i] == '\n' || !str[i])
	{
		if (*xt)
			if (*xt != info->x_map_size)
				return (0);
		*xt = info->x_map_size;
		info->x_map_size = 0;
		info->y_map_size++;
		if (!str[i] || !str[i + 1])
			return (ft_fill_x_map_size(*xt, info));
		i++;
	}
	*i1 = i;
	return (2);
}

int		ft_check_input(char *str, t_info *info)
{
	int		i;
	int		chk;
	int		xt;

	i = 0;
	xt = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '-')
		{
			i++;
		}
		if ((chk = ft_check_input_loop(&i, &xt, str, info)) != 2)
			return (chk);
		while (str[i] == ' ' || str[i] == '-')
		{
			i++;
		}
	}
	return (0);
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
