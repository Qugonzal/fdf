/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:25:23 by qugonzal          #+#    #+#             */
/*   Updated: 2017/11/11 18:30:16 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cpy_and_free(const char *str, char **tmp)
{
	char	*ptr;

	ptr = *tmp;
	*tmp = ft_strjoin(*tmp, str);
	ft_strdel(&ptr);
	return (*tmp);
}

char	*cpy_to_nl(char *read, char **tmp)
{
	char	*line;
	char	*ptr;
	int		n;
	int		i;

	n = 0;
	i = -1;
	if (*read)
	{
		ptr = *tmp;
		*tmp = ft_strjoin(*tmp, read);
		free(ptr);
	}
	while ((*tmp)[n] != '\n')
		n++;
	line = ft_memalloc(n + 1);
	while ((++i != -1) && n-- > 0)
		line[i] = (*tmp)[i];
	ptr = *tmp;
	*tmp = ft_strdup(&ptr[i + 1]);
	free(ptr);
	return (line);
}

int		line_check(char *str, char **tmp, char **line, int i)
{
	char	*chk;

	if (i == -1)
	{
		ft_strdel(&str);
		return (-1);
	}
	else if ((chk = ft_strchr(str, '\n')))
	{
		*line = cpy_to_nl(str, tmp);
		return (1);
	}
	else if ((0 < i && i < BUFF_SIZE))
	{
		*line = ft_strdup(cpy_and_free(str, tmp));
		ft_strdel(tmp);
		ft_strdel(&str);
		return (1);
	}
	else
	{
		cpy_and_free(str, tmp);
		ft_bzero(str, BUFF_SIZE);
	}
	return (0);
}

int		ft_free(char *str, char **tmp, char **line)
{
	if (str && *str)
		ft_strdel(&str);
	if (*tmp)
	{
		*line = ft_strdup(*tmp);
		if (**tmp)
		{
			ft_strdel(tmp);
			return (1);
		}
		ft_strdel(tmp);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	int				j;
	char			*chk;
	char			*str;
	static t_line	tmp;

	if (!tmp.s)
		tmp.s = (char *)ft_memalloc(1);
	if ((chk = ft_strchr(tmp.s, '\n')))
		return (*line = cpy_to_nl("", &tmp.s)) ? 1 : 1;
	str = ft_memalloc(BUFF_SIZE + 1);
	while ((i = read(fd, str, BUFF_SIZE)))
		if ((j = line_check(str, &tmp.s, line, i)))
			return (j);
	if (ft_free(str, &tmp.s, line))
		return (1);
	return (0);
}
