#include "lem_in.h"

t_data	*get_data_input(t_data_input *data_input)
{
	char			*line;
	t_data_input	*tmp;

	tmp = data_input;
	//временно для чтения данных из файла
	// int f;
	// f = open("maps/test02.map", O_RDWR);
	// f = open("maps/big/map_big_2", O_RDWR);
	// f = open("maps/invalid/room_coord_duplicated", O_RDWR);

	//------------------------------------
	// f убрать и поставить стандартный ввод 0
	//STDIN_FILENO
	while (get_next_line(0, &line) > 0)
	{
		tmp->str = line;
		tmp->next = new_data_inputlist();
		tmp = tmp->next;
		ft_printf("%s\n", line);
	}
	ft_printf("\n");
	return (parse_data(data_input));
}
