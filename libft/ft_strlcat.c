/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:47:56 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:03:38 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(dst);
	if (l >= size)
		return (ft_strlen(src) + size);
	size--;
	while (src[i] && i < size - l)
	{
		dst[l + i] = src[i];
		i++;
	}
	dst[l + i] = '\0';
	return (ft_strlen(src) + l);
}
