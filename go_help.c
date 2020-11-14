/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:19:11 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/14 16:40:48 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			start_end(t_ways *ways_tm, t_flags *flags)
{
	flags->lim_end++;
	ft_printf("L%d-%s ", flags->lim_start, ways_tm->name_room_way);
	flags->lim_start--;
}

void			go_end(t_ways *ways_tm, t_flags *flags)
{
	flags->lim_end++;
	ways_tm->name_lim = ways_tm->way->name_lim;
	ways_tm->lim++;
	ways_tm->way->lim = 0;
	ways_tm->way->name_lim = 0;
	ft_printf("L%d-%s ", ways_tm->name_lim, ways_tm->name_room_way);
}

void			go_out_start(t_ways *ways_tm, t_flags *flags)
{
	ways_tm->name_lim = flags->lim_start;
	flags->lim_start--;
	ways_tm->lim = 1;
	ft_printf("L%d-%s ", ways_tm->name_lim, ways_tm->name_room_way);
}

void			clean_data_input(t_data_input *data_input)
{
	t_data_input	*tmp;

	if (data_input != NULL)
	{
		while (data_input->next != NULL)
		{
			tmp = data_input;
			data_input = data_input->next;
			if (tmp->str)
				free(tmp->str);
			free(tmp);
		}
		if (data_input->str)
			free(data_input->str);
		free(data_input);
	}
}
