/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:35:49 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:02:28 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int		ft_digitlen(const char *str)
{
	long int	i;

	i = 1;
	while (ft_isdigit(*++str))
		i *= 10;
	return (i);
}

int					ft_atoi_recursive(const char *str)
{
	long int	res[3];

	if (!str || !*str)
		return (0);
	res[0] = ft_isdigit(*str) ? *str - '0' : 0;
	if (ft_strchr("\t\n\r\v\f ", *str) && res[0] == 0)
		return (ft_atol(str + 1));
	if (ft_strchr("+-", *str) && ft_isdigit(*(str + 1)))
		return (ft_atol(str + 1));
	else if (ft_strchr("+-", *str) && !ft_isdigit(*(str + 1)))
		return (0);
	if (ft_isdigit(*(str)))
	{
		res[1] = *(str - 1) == '-' ? -1 : 1;
		res[2] = ft_isdigit(*(str + 1)) ? ft_atol(str + 1) : 0;
		res[0] = res[0] * ft_digitlen(str);
		if (res[2] >= 0 && (res[0] + res[2]) >= res[0])
			res[0] = (res[0] + res[2]) * res[1];
		else
			res[0] = res[1] > 0 ? -1 : (int)NULL;
	}
	return (res[0]);
}
