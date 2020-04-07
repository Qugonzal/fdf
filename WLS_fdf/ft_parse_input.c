#include "fdf.h"

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

int		*ft_nb_strsplit(char *str, t_info *info, int y)
{
	char	**tab_str;
	int		*tab;
	int		x;

	if (!(tab_str = ft_strsplit(str, ' ')))
		ft_error("ft_strsplit", str);
	free(str);
	x = 0;
	while (tab_str[x])
		x++;
	info->x_map_size = x;
//	ft_fill_colors(tab_str, info, y);
	if (!(tab = (int *)malloc(sizeof(int) * x)))
		ft_error("in ft_nb_strsplit: malloc failed", 0);
	x = 0;
	while (tab_str[x])
	{
		tab[x] = ft_atoi(tab_str[x]);
		free(tab_str[x]);
		x++;
	}
	free(tab_str);
	return (tab);
}

void	ft_strtab_to_int(char **tab_str, t_info *info)
{
	int		i;

	if (!(info->map = (int **)malloc(sizeof(int *) * info->y_map_size)))
		ft_error("malloc", 0);
//	if (ft_strstr(tab_str[0], ",0x"))
//		if (!(info->colors = (int **)malloc(sizeof(int *) * info->y_map_size)))
//			ft_error("malloc", 0);
	i = 0;
	while (i < info->y_map_size)
	{
		if (!(info->map[i] = ft_nb_strsplit(tab_str[i], info, i)))
		{
			while (--i >= 0)
				free(info->map[i]);
			while (i <= info->y_map_size)
				free(tab_str[i]);
			free(tab_str);
			ft_error("ft_nb_strsplit", info->map);
		}
		i++;
	}
	free(tab_str[i]);
	free(tab_str);
}

char 	*ft_read(int fd)
{
	int		i;
	char	buf[51];
	char	*tmp;
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) + 1)))
	{
		ft_putstr("malloc returned NULL\n");
		exit(-1);
	}
	ft_bzero(str, 2);
	i = 0;
	while ((i = read(fd, buf, 50)))
	{
		if (i == -1)
		{
			ft_putstr("read returned -1\n");
			exit(EXIT_FAILURE);
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
		ft_putstr("open returned -1\n");
		exit(-1);
	}
	str = ft_read(fd);
	close(fd);
	return (str);
}

int		**ft_parse_input(char *file, t_info *info)
{
	int		y;
	char	*str;
	char	**tab_str;

	str = ft_open_read(file);
	if (!(tab_str = ft_strsplit(str, '\n')))
		ft_error("ft_strsplit", 0);
	free(str);
	y = 0;
	while (tab_str[y])
		y++;
	info->y_map_size = y;
	ft_strtab_to_int(tab_str, info);
	return (info->map);
}
