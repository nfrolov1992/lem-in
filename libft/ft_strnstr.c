/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:23:19 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:03:46 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		h[len];
	char		*res;
	size_t		i;

	i = 0;
	while (i < len)
	{
		h[i] = haystack[i];
		i++;
	}
	h[i] = '\0';
	res = ft_strstr(h, needle);
	if (res)
		res = ft_strstr(haystack, res);
	return (res);
}
