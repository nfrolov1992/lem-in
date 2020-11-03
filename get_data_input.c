#include "lem_in.h"

t_data	*get_data_input(t_data_input *data_input)
{
	char			*line;
	t_data_input	*tmp;

	tmp = data_input;
	//временно для чтения данных из файла
	int f;
	// f = open("maps/test06.map", O_RDWR);
	// f = open("maps/big/map_big_2", O_RDWR);
	f = open("maps/big_sup/map_big_sup_6", O_RDWR);

	//------------------------------------
	// f убрать и поставить стандартный ввод 0
	//STDIN_FILENO
	while (get_next_line(f, &line) > 0)
	{
		tmp->str = line;
		tmp->next = new_data_inputlist();
		tmp = tmp->next;
		//---------------ВЫВОД-----------------//
		//ft_printf("%s", line);
		//ft_printf("\n");
		//-------------------------------------//
	}
	return (parse_data(data_input));
}
