/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:30:53 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/04 13:02:23 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flags(t_arg *a)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (a->flags[j])
	{
		if (a->type == 37)
			return (0);
		if (ft_strchr("# -+*.0123456789hLlcspdiouxXfjztU%", a->flags[j]))
			++j;
		else
			return (-2);
	}
	return (0);
}
