/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:26:09 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 13:03:56 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	line_output(char **cont_line, char **line, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (cont_line[fd][i] != '\n' && cont_line[fd][i] != '\0')
		i++;
	if (cont_line[fd][i] == '\n')
	{
		*line = ft_strsub(cont_line[fd], 0, i);
		tmp = ft_strdup(cont_line[fd] + i + 1);
		free(cont_line[fd]);
		cont_line[fd] = tmp;
		if (cont_line[fd][0] == '\0')
			ft_strdel(&cont_line[fd]);
	}
	else if (cont_line[fd][i] == '\0')
	{
		*line = ft_strdup(cont_line[fd]);
		ft_strdel(&cont_line[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*cont1[10240];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL || fd > 10239)
		return (-1);
	if (cont1[fd] == NULL)
		cont1[fd] = ft_strnew(1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(cont1[fd], buff);
		free(cont1[fd]);
		cont1[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (cont1[fd] == NULL || cont1[fd][0] == '\0'))
		return (0);
	return (line_output(cont1, line, fd));
}
