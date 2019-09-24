#include "fdf.h"

int		*ft_nb_strsplit(char *str, t_info *info)
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
	if (!(tab = (int *)malloc(sizeof(int) * x - 1)))
		ft_error("malloc", 0);
	x = 0;
	while (tab_str[x])
	{
		tab[x] = ft_atoi(tab_str[x]);
		free(tab_str[x]);
		x++;
	}
	free(tab_str[x]);
	free(tab_str);
	return (tab);
}

int		**ft_strtab_to_int(char **tab_str, t_info *info)
{
	int		**map;
	int		i;

	if (!(map = (int **)malloc(sizeof(int *) * i - 1)))
		ft_error("malloc", 0);
	i = 0;
	while (i < info->y_map_size)
	{
		if (!(map[i] = ft_nb_strsplit(tab_str[i], info)))
		{
			while (--i >= 0)
				free(map[i]);
			while (i <= info->y_map_size)
				free(tab_str[i]);
			free(tab_str);
			ft_error("ft_nb_strsplit", map);
		}
		i++;
	}
	return (map);
}

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

int		**ft_parse_input(char *file, t_info *info)
{
	int		**map;
	int		y;
	int		x;
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
	map = ft_strtab_to_int(tab_str, info);
	return (map);
}
