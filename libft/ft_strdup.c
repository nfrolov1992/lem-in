/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:13:49 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:03:34 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*res;
	size_t	l;

	res = NULL;
	l = 0;
	l = ft_strlen(s1);
	if (!(res = ft_strnew(l)))
		return (NULL);
	l = 0;
	while (s1[l])
	{
		res[l] = s1[l];
		++l;
	}
	res[l] = 0;
	return (res);
}
