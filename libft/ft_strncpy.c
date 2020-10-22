/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:25:15 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:03:43 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		t;

	i = 0;
	t = 0;
	while (i < len)
	{
		if (src[i] && t == 0)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		if (src[i] == '\0')
			t = 1;
		++i;
	}
	return (dst);
}
