/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:13:04 by namina            #+#    #+#             */
/*   Updated: 2022/01/28 19:18:18 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER 68

static int	checkfor_n(char *s)
{
	char	*tmp;

	tmp = s;
	while (*tmp)
	{
		if (*tmp == '\n')
			return ((int)(tmp - s));
		tmp++;
	}
	return (-1);
}

static int	fill_line(t_set_fd *current_el, char **line, int len_to_line)
{
	char	**str;

	str = &(current_el->str);
	*line = ft_strdup_gnl(*str, len_to_line, 0);
	if (!(*line))
		return (-1);
	*str = ft_strdup_gnl(*str, ft_strlen_gnl(*str) - len_to_line - 1,
			len_to_line + 1);
	if (!(*str))
		return (-1);
	if (!(current_el->read_res))
		return (0);
	else
		return (1);
}

static void	first_read(t_set_fd *current_el, char **buf)
{
	current_el->read_res = read(current_el->fd, *buf, BUFFER);
	if (current_el->read_res == -1)
		return ;
	current_el->str = ft_strdup_gnl(*buf, current_el->read_res, 0);
}

int	main_read(char **line, char **buf, t_set_fd *current_el)
{
	int		len_to_line;

	current_el->read_res = 1;
	while (current_el->read_res > 0)
	{
		len_to_line = checkfor_n(current_el->str);
		if (len_to_line != -1)
			return (fill_line(current_el, line, len_to_line));
		else
		{
			current_el->read_res = read(current_el->fd, *buf, BUFFER);
			if (current_el->read_res == -1)
				return (-1);
			if (!current_el->read_res && current_el->str)
				return (fill_line(current_el, line,
						ft_strlen_gnl(current_el->str)));
			(*buf)[current_el->read_res] = '\0';
			current_el->str = ft_strjoin_gnl(current_el->str, *buf,
					current_el->read_res);
			if (!(current_el->str))
				return (-1);
		}
	}
	return (current_el->read_res);
}

int	get_next_line(int fd, char **line)
{
	static t_set_fd	*list;
	char			*buf;
	t_set_fd		*current_el;

	current_el = get_current_el(&list, fd);
	if (!current_el)
		return (-1);
	buf = malloc(BUFFER);
	if (!buf)
		return (-1);
	if (!(current_el->str))
		first_read(current_el, &buf);
	if (current_el->read_res == -1)
	{
		free(buf);
		lst_free(&list);
		return (-1);
	}
	current_el->read_res = main_read(line, &buf, current_el);
	if (current_el->read_res == -1 || current_el->read_res == 0)
		lst_free(&list);
	free(buf);
	return (current_el->read_res);
}
