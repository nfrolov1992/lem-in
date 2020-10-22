#include "lem_in.h"

void	run_lim_run(int count_lim, t_data_ways *data_ways)
{
	t_data_ways		*data_ways_tm;
	t_ways			*ways_tm;
	int				lim_end;
	int				lim_start;

	data_ways_tm = data_ways;
	lim_end = 0;
	lim_start = count_lim;
	while (lim_end != count_lim)
	{
		if (data_ways->way == NULL && data_ways->next_way == NULL)
		{
			data_ways = data_ways_tm;
			ft_printf("\n");
		}
		if (data_ways->mod == 0)
		{
			ways_tm = data_ways->way;
			while (ways_tm->way->start != 1)
			{
				// находясь в комнате end,  смотрим в следующей комнате есть ли лим и взависимости от того есть или нет переносим или нет.
				// if (ways_tm->end == 1 && ways_tm->way->lim == 0) // если нет лима, просто переходим
				// 	ways_tm = ways_tm->way;
				if (ways_tm->end == 1 && ways_tm->way->lim == 1) // если есть лим в следующей комнате
				{
					lim_end++;
					ways_tm->name_lim = ways_tm->way->name_lim;
					ways_tm->lim++;
					ways_tm->way->lim = 0;
					ways_tm->way->name_lim = NULL;
					ft_printf("L%s-%s ", ways_tm->name_lim, ways_tm->name_room_way);
				}
				// если подошли к началу
				else if (ways_tm->way->way->start == 1 && lim_start != 0)
				{
					ways_tm->name_lim = ft_itoa(lim_start);
					lim_start--;
					ways_tm->lim = 1;
					ft_printf("L%s-%s ", ways_tm->name_lim, ways_tm->name_room_way);
				}
				// середина пути
				else if (ways_tm->way->lim == 1)
				{
					ways_tm->lim = 1;
					ways_tm->name_lim = ways_tm->way->name_lim;
					ways_tm->way->lim = 0;
					ways_tm->way->name_lim = NULL;
					ft_printf("L%s-%s ", ways_tm->name_lim, ways_tm->name_room_way);
				}
				
				ways_tm = ways_tm->way;
			}
			data_ways = data_ways->next_way;
		}
		else
		{
			data_ways = data_ways->next_way;
		}
		
	}

}