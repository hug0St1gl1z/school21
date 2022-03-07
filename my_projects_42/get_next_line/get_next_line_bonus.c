/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:57:28 by cblanca           #+#    #+#             */
/*   Updated: 2021/11/27 12:57:11 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(int fd, char *line)
{
	char	*buf;
	int		flag;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	flag = 1;
	while (!pointer_to_end_line(line) && flag)
	{
		flag = read(fd, buf, BUFFER_SIZE);
		if (flag == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[flag] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*line_after_n(char *line)
{
	char	*remainder;
	int		counter;
	int		counter2;

	counter = 0;
	if (!line)
		return (NULL);
	while (line[counter] != '\n' && line[counter])
		counter++;
	if (!line[counter])
	{
		free(line);
		return (NULL);
	}
	remainder = malloc(ft_strlen(&line[counter]) + 1);
	if (!remainder)
		return (NULL);
	counter++;
	counter2 = 0;
	while (line[counter])
		remainder[counter2++] = line[counter++];
	remainder[counter2] = '\0';
	free(line);
	return (remainder);
}

char	*line_before_n(char *line)
{
	int		counter;
	char	*remainder;

	counter = 0;
	if (!line)
		return (NULL);
	while (line[counter] != '\n' && line[counter])
		counter++;
	if (line[counter] == '\n')
		counter++;
	remainder = malloc(counter + 1);
	if (!remainder)
		return (NULL);
	counter = 0;
	while (line[counter] != '\0' && line[counter] != '\n')
	{
		remainder[counter] = line[counter];
		counter++;
	}
	if (line[counter] == '\n')
		remainder[counter++] = '\n';
	remainder[counter] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*remain;
	static char	*line[FD_MAX_COUNT] = {0};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = get_line(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	remain = line_before_n(line[fd]);
	if (!remain || !*remain)
	{
		free(remain);
		if (line[fd])
		{
			free(line[fd]);
			line[fd] = NULL;
		}
		return (NULL);
	}
	line[fd] = line_after_n(line[fd]);
	return (remain);
}
