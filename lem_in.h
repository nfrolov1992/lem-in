#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

// структура данных из подаваемой карты без парсинга (далее эта структура преобразуется используемы данные)
typedef struct				s_data_input
{
	char					*str;
	struct s_data_input		*next;
}							t_data_input;

//структура данных комната
typedef struct				s_data_room
{
	char					*name;
	int						start;
	int						end;
	int						length;
	int						use_room;
	char					*from_link;
	char					*coord_x;
	char					*coord_y;
	struct s_data_room		*next;
}							t_data_room;

//структура даных ссылка
typedef struct				s_data_link
{
	char					*from;
	struct s_data_room		*from_room;
	char					*to;
	struct s_data_room		*to_room;
	int						weight;
	int						act;
	int						count_way;
	struct s_data_link		*next;
}							t_data_link;


//общая структура содержащая ссылку и комнату
typedef struct				s_data
{
	struct s_data_room		*rooms;
	struct s_data_link		*links;
	int						count_way;
}							t_data;

typedef struct				s_ways
{
	char					*name_room_way;
	char					*name_lim;
	int						end;
	int						start;
	int						lim;
	int						no_use;
	struct s_ways			*way;
	struct s_ways			*way_prev;
}							t_ways;

typedef struct				s_data_ways
{
	int						mod;
	int						bad_way;
	struct s_ways			*way;
	struct s_data_ways		*next_way;
}							t_data_ways;

typedef struct				s_check_ways
{
	int						use_chnge_way;
	struct s_ways			*way1;
	struct s_ways			*way2;
}							t_check_ways;

t_data_input				*new_data_inputlist(void);
t_data						*get_data_input(t_data_input *data_input);
t_data						*parse_data(t_data_input *data_input);
t_data_room					*new_data_roomlist(void);
t_data_link					*new_data_linklist(void);
t_data						*new_datalist(void);
void						bellamna_ford(t_data_room *rooms, t_data_link *links);
t_data_ways					*new_ways_datalist(void);
t_ways						*new_wayslist(void);
t_ways						*save_way(t_data_room *rooms);
t_data						*base_setting(t_data_room *rooms, t_data_link *links, t_ways *ways);
t_ways						*save_new_way(t_data_room *rooms, t_data_ways *data_ways_tm, t_data_ways *data_ways);
t_check_ways				*new_check_way(void);
t_data						*base_setting_bad_way(t_data_room *rooms, t_data_link *links, t_ways *ways);
void						run_lim_run(int count_lim, t_data_ways *ways);


#endif