/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:52:26 by quegonza          #+#    #+#             */
/*   Updated: 2019/04/10 15:36:51 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		ls1;
	int		ls2;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	if (!(new = (char *)ft_memalloc(ls1 + ls2 + 1)))
		return (NULL);
	ft_strncpy(new, s1, ls1);
	ft_strncpy(&new[ls1], s2, ls2);
	return (new);
}
