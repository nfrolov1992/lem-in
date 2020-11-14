/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_lim_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:26:43 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/14 16:38:13 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_go(t_data_ways *data_ways, int count_lim)
{
	int		length_way;
	int		length_prev;
	int		i;

	length_way = data_ways->length_way;
	length_prev = 0;
	i = 0;
	if (data_ways->length_way == 1 || count_lim == 0)
		return (1);
	while (data_ways->prev_way != NULL)
	{
		i++;
		data_ways = data_ways->prev_way;
		length_prev = length_prev + data_ways->length_way;
	}
	length_way = length_way * i;
	if (count_lim > length_way - length_prev)
		return (1);
	else
		return (0);
}

static void		go_middle(t_ways *ways_tm, t_flags *flags)
{
	ways_tm->lim = 1;
	ways_tm->name_lim = ways_tm->way->name_lim;
	ways_tm->way->lim = 0;
	ways_tm->way->name_lim = -1;
	ft_printf("L%d-%s ", ways_tm->name_lim, ways_tm->name_room_way);
}

static void		next_ways(t_data_ways **data_ways, t_data_ways *data_ways_tm)
{
	*data_ways = data_ways_tm;
	ft_printf("\n");
}

static void		route_lims(t_flags f, t_data_ways *d_way,
				t_data_ways *d_way_tm, t_ways *way_m)
{
	while (f.lim_end != f.count_lim)
	{
		if (d_way->way == NULL && d_way->next_way == NULL)
			next_ways(&d_way, d_way_tm);
		if (d_way->length_way != 0)
		{
			way_m = d_way->way;
			while (way_m->way->start != 1)
			{
				if (way_m->end == 1 && way_m->way->way->name_room_way == NULL)
					start_end(way_m, &f);
				else if (way_m->end == 1 && way_m->way->lim == 1)
					go_end(way_m, &f);
				else if (way_m->way->way->start == 1 && f.lim_start != 0 &&
						((d_way->first_way == 1) || is_go(d_way, f.lim_start)))
					go_out_start(way_m, &f);
				else if (way_m->way->lim == 1)
					go_middle(way_m, &f);
				way_m = way_m->way;
			}
			d_way = d_way->next_way;
		}
		else
			d_way = d_way->next_way;
	}
}

void			run_lim_run(int count_lim, t_data_ways *data_ways)
{
	t_data_ways		*data_ways_tm;
	t_ways			*ways_tm;
	t_flags			flags;

	flags.count_lim = count_lim;
	data_ways_tm = data_ways;
	flags.lim_end = 0;
	flags.lim_start = count_lim;
	data_ways->first_way = 1;
	route_lims(flags, data_ways, data_ways_tm, ways_tm);
}
