/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 01:52:27 by mozzart           #+#    #+#             */
/*   Updated: 2020/03/04 13:03:10 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*r;
	char	*s;
	size_t	i;

	i = 0;
	r = (char*)dst;
	s = (char*)src;
	if (s < r)
		while ((int)(--len) >= 0)
			r[len] = s[len];
	if (s > r)
		while (i < len)
		{
			r[i] = s[i];
			i++;
		}
	return (r);
}
