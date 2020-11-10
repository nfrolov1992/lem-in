#include "lem_in.h"

t_data	*get_data_input(t_data_input *data_input)
{
	char			*line;
	t_data_input	*tmp;

	tmp = data_input;
	//временно для чтения данных из файла
	// int f;
	// f = open("maps/map_simple1", O_RDWR);

	//------------------------------------
	// f убрать и поставить стандартный ввод 0
	//STDIN_FILENO// maps/map_simple1
	while (get_next_line(0, &line) > 0)
	{
		tmp->str = line;
		tmp->next = new_data_inputlist();
		tmp = tmp->next;
		//---------------ВЫВОД-----------------//
		ft_printf("%s", line);
		ft_printf("\n");
		//-------------------------------------//
	}
	return (parse_data(data_input));
}
