/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:04:35 by quegonza          #+#    #+#             */
/*   Updated: 2020/05/02 19:06:27 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_read(int fd)
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
