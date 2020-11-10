/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:41:29 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/10 18:18:10 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	terminate(char *message)
{
	write(1, "\x1B[31m", 5);
	ft_putendl(message);
	write(1, "\x1b[37m", 5);
	exit(1);
}

int		is_positive_int(char *str)
{
	unsigned long	res;

	res = 0;
	if (str == NULL)
		return (-1);
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (-1);
		res = res * 10 + (*str - '0');
		if (res > 2147483647)
			return (-1);
		str++;
	}
	return ((int)res);
}

void	print_farm(t_data *data_lim)
{
	t_data_room	*rooms;
	t_data_link	*links;

	rooms = data_lim->rooms;
	links = data_lim->links;
	while (rooms->next != NULL)
	{
		ft_printf("%6s %3s %3s %d %d length:%d\n", rooms->name, rooms->coord_x,
			rooms->coord_y, rooms->start, rooms->end, rooms->length);
		rooms = rooms->next;
	}
	while (links->next != NULL)
	{
		ft_printf("%6s-%s  act=%d\n", links->from, links->to, links->act);
		links = links->next;
	}
	return ;
}
