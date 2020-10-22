/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:29:24 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:03:05 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*r;

	r = NULL;
	if (!(r = (void*)malloc(size)))
		return (NULL);
	ft_memset(r, 0, size);
	return (r);
}
