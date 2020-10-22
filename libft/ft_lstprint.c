/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:26:29 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:02:56 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstprint(t_list *lst)
{
	if (lst)
	{
		if (lst->content)
			ft_putendl(lst->content);
		if (lst->next)
			ft_lstprint(lst->next);
	}
}
