/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:53:42 by ssacrist          #+#    #+#             */
/*   Updated: 2021/11/30 10:04:21 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	append_buf(char **line, char *buf)
{
	char	*tmp;
	int	i = 0;

	while ((*line)[i])
		i++;
	tmp = malloc(i + 2);
	i = 0;
	while ((*line)[i])
	{
		tmp[i] = (*line)[i];
		i++;
	}
	tmp[i] = buf[0];
	tmp[i + 1] = '\0';
	free(*line);
	*line = tmp;
}

int	get_next_line(char **line)
{
	char	buf[2];
	int		bytes;

	buf[1] = '\0';
	*line = malloc(1);
	(*line)[0] = '\0';
	bytes = 0;
	while ((bytes = read(0, buf, 1) > 0))
	{
		if (buf[0] == '\n')
			return (1);
		append_buf(line, buf);
	}
	if (bytes < 0)
	{
		if (*line)
			free(*line);
		return (-1);
	}
	return (0);
}