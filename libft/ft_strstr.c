/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:25:41 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:03:49 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*res;
	int		in;

	res = (char*)haystack;
	in = 0;
	while (*haystack)
	{
		if (needle[in] && *haystack == needle[in])
		{
			if (in == 0)
				res = (char*)haystack;
			in++;
		}
		else if (!needle[in])
			break ;
		else if (in != 0)
			return (ft_strstr((haystack - in + 1), needle));
		haystack++;
	}
	if (ft_strlen(needle) > ft_strlen(res) || (in == 0 && needle[0] != 0))
		return (NULL);
	return (res);
}
