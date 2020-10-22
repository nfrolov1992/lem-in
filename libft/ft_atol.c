/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:45:27 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:02:29 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atol(const char *str)
{
	int		i;
	int		min;
	long	result;

	i = 0;
	min = 1;
	result = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 13 || str[i] == 11
			|| str[i] == 12 || str[i] == 32)
		i++;
	if (str[i] == 45)
		min = -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		result = (result * 10) + (str[i++] - 48);
	return (result *= min);
}
