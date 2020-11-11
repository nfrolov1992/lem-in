#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct				s_data_input
{
	char					*str;
	struct s_data_input		*next;
}							t_data_input;

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
	int						length_way;
	int						start;
	int						lim;
	int						no_use;
	struct s_ways			*way;
	struct s_ways			*way_prev;
}							t_ways;

typedef struct				s_data_ways
{
	int						length_way;
	int						first_way;
	struct s_ways			*way;
	struct s_data_ways		*next_way;
	struct s_data_ways		*prev_way;
}							t_data_ways;

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
void						base_setting(t_data *data_lim, t_ways *ways);
void						run_lim_run(int count_lim, t_data_ways *ways);
void						terminate(char *message);
int							is_positive_int(char *str);
int							is_good_int(char *str);
int							looks_like_link(char *str);
void						print_farm(t_data *data_lim);
void						parse_links(t_data_input *data_input, t_data *data_lim);
void    					clean_datalists(t_data *data_lim, t_data_input *data_input, \
								t_data_ways *data_ways);

#endif
