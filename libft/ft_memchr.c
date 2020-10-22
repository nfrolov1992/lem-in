/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:35:50 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:03:07 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*r;

	r = (unsigned char*)s;
	c = (unsigned char)c;
	while (n > 0)
	{
		if (*r == c)
			return (r);
		n--;
		r++;
	}
	return (NULL);
}
