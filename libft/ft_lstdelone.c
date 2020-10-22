/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:55:49 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:02:52 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*l;

	if (!alst || !*alst || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	l = (*alst)->next;
	free(*alst);
	*alst = NULL;
}
