/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstapend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 22:20:46 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:02:44 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstapend(t_list **lst, t_list *new)
{
	if (*lst)
	{
		if ((*lst)->next)
			ft_lstapend(&(*lst)->next, new);
		else
			(*lst)->next = new;
	}
}
