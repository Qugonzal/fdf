/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:51:35 by quegonza          #+#    #+#             */
/*   Updated: 2019/04/10 14:57:24 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
