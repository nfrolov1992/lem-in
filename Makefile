# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:27:16 by tvanessa          #+#    #+#              #
#    Updated: 2020/11/01 16:17:00 by fprovolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = 
SS = $(S)lem_in.c $(S)get_data_input.c $(S)new_data_inputlist.c $(S)parse_data.c $(S)bellam_ford.c $(S)save_way.c $(S)base_setting.c $(S)run_lim_run.c $(S)tools.c
H = -I libft/includes -I libft/ -I .
NAME = lem_in
CC = clang
CF = -g -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CF) $(H) -c -o $@ $<

$(NAME): libbuild $(SS:.c=.o)
	$(CC) $(CF) $(H) -o $(NAME) $(SS:.c=.o) -L libft/ -lft

libbuild:
	make -C libft/ 

clean:
	make -C libft/ clean 
	/bin/rm -f $(SS:.c=.o)

fclean: clean
	make -C libft/ fclean 
	/bin/rm -f libft.a
	/bin/rm -f $(NAME)

re: fclean all
