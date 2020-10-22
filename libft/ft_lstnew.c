/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:32:40 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:02:55 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	if (!(l = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		l->content = NULL;
		l->content_size = 0;
	}
	else
	{
		if ((content_size + 1) == 0 ||
		!(l->content = (void*)malloc(content_size)))
			return (ft_free((void**)&l));
		ft_memcpy(l->content, content, content_size);
		l->content_size = content_size;
	}
	l->next = NULL;
	return (l);
}
