/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:03:34 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:03:45 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t		sc;
	char		*str;
	size_t		i;

	sc = sizeof(char);
	str = NULL;
	if ((size + 1) == 0 || !(str = (char*)malloc(sc * (size + sc))))
		return (NULL);
	i = 0;
	while (i < (size + sc))
		str[i++] = 0x0;
	return (str);
}
