/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:03:37 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:05:25 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*r;
	size_t	l;
	size_t	j;

	if (!s)
		return (NULL);
	r = NULL;
	j = 1;
	l = 0;
	while (ft_strchr(" \n\t", *s) && *s)
		++s;
	if (*s)
	{
		l = ft_strlen(s);
		while (ft_strchr(" \n\t", *(s + l - j)) && *(s + l - j))
			++j;
	}
	--j;
	if ((r = ft_strnew(l - j)))
		r = ft_strncpy(r, s, l - j);
	return (r);
}
