/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 21:08:50 by rmaury            #+#    #+#             */
/*   Updated: 2015/02/10 14:54:08 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	sub_line(char **line, char **str, int ret)
{
	char	*tmp;

	if (ret == -1)
		return ;
	tmp = *line;
	*line = ft_strsub(*line, 0, *str - *line);
	free(tmp);
	*str = ft_strdup(*str + 1);
}

static void	join_line(char **line, char *buff, int ret)
{
	char	*tmp;

	buff[ret] = '\0';
	tmp = *line;
	(*line) = ft_strjoin(*line, buff);
	free(tmp);
}

int			get_next_line(int fd, char **line)
{
	static char	*str;
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (!line && fd != 0)
		return (-1);
	if (fd > -1)
	{
		*line = ft_strnew(1);
		if (str)
		{
			(*line) = ft_strdup(str);
			free(str);
		}
		while (((str = ft_strchr(*line, '\n')) == NULL)
			&& ((ret = read(fd, buff, BUFF_SIZE)) > 0))
			join_line(line, buff, ret);
		if (ret == 0 && str == NULL)
			return (0);
		sub_line(line, &str, ret);
		return ((ret == -1) ? -1 : 1);
	}
	else
		return (-1);
}
