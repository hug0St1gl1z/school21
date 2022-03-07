/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:10:19 by namina            #+#    #+#             */
/*   Updated: 2022/01/28 19:18:09 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup_gnl(char *src, int len, int offset)
{
	char	*p_res;
	int		i;

	i = 0;
	p_res = malloc(len + 1);
	if (!p_res)
		return (NULL);
	while (i < len)
	{
		p_res[i] = src[i + offset];
		i++;
	}
	p_res[i] = '\0';
	if (offset)
		free(src);
	return (p_res);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int len)
{
	char	*new;
	char	*p_s1;
	char	*p_s2;

	p_s1 = s1;
	p_s2 = s2;
	new = malloc(ft_strlen_gnl(s1) + len + 1);
	if (!new)
		return (NULL);
	while (*p_s1)
	{
		*new = *p_s1;
		p_s1++;
		new++;
	}
	while (*p_s2)
	{
		*new = *p_s2;
		p_s2++;
		new++;
	}
	*new = '\0';
	free(s1);
	return (new - ((p_s1 - s1) + (p_s2 - s2)));
}

t_set_fd	*get_current_el(t_set_fd **list, int fd)
{
	t_set_fd	*tmp;
	t_set_fd	*prev;
	t_set_fd	*new_el;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		prev = tmp;
		tmp = tmp->next;
	}
	new_el = malloc(sizeof(t_set_fd));
	if (!new_el)
		return (NULL);
	new_el->fd = fd;
	new_el->next = NULL;
	new_el->str = NULL;
	if (!(*list))
		*list = new_el;
	else
		prev->next = new_el;
	return (new_el);
}

void	lst_free(t_set_fd **list)
{
	t_set_fd	*tmp;
	t_set_fd	*next;

	tmp = *list;
	while (tmp)
	{
		if (tmp->read_res > 0)
			return ;
		tmp = tmp->next;
	}
	tmp = *list;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->str);
		free(tmp);
		tmp = next;
	}
	*list = NULL;
}
