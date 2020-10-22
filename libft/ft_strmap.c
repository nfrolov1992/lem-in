/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:40:44 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:03:40 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*r;
	size_t		cs;
	size_t		l;
	size_t		i;

	r = NULL;
	if (!s || !f)
		return (r);
	cs = sizeof(char);
	l = ft_strlen(s);
	if (!(r = ft_strnew(l)))
		return (r);
	i = 0;
	while (i < l)
	{
		r[i] = (f)(s[i]);
		++i;
	}
	return (r);
}
