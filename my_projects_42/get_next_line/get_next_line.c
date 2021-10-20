/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:31:14 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/20 10:36:41 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(*str) * (1));
		if (str)
		{
			memset(str, '\0', (1));
			return (str);
		}
	}
	else if (size)
	{
		str = (char *)malloc(sizeof(*str) * (size + 1));
		if (str)
		{
			memset(str, '\0', (size + 1));
			return (str);
		}
	}
	return (NULL);
}

char	chek_remainder(char *remainder, char **line)
{
	char	*p_n;

	p_n = 0;
	if (remainder)
	{
		if ((strchr(remainder, '\n')))
		{
			*p_n = '\0';
			*line = strdup(remainder);
			strcpy(remainder, ++p_n);
		}
		else
		{
			*line = strdup(remainder);
			bzero(remainder, strlen(remainder));
		}
	}
	else
	{
		*line = ft_strnew(1);
	}
	return (*p_n);
}

char	*ft_strjjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	s1s2_len;
	char	*rtn;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (strdup(s1));
	if (!s1 && s2)
		return (strdup(s2));
	s1_len = strlen(s1);
	s2_len = strlen(s2);
	s1s2_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * s1s2_len);
	if (!rtn)
		return (0);
	memmove(rtn, s1, s1_len);
	memmove(rtn + s1_len, s2, s2_len);
	rtn[s1s2_len - 1] = '\0';
	return (rtn);
}

int	get_next_line(int fd, char **line)
{
	char		c[10 + 1];
	int			byte_read;
	char		*p_n;
	static char	*remainder;

	*p_n = chek_remainder(remainder, line);
	while (!p_n && (byte_read = read(fd, c, 10)))
	{
		c[byte_read] = '\0';
		if ((p_n = strchr(c, '\n')))
		{
			*p_n = '\0';
			p_n++;
			remainder = strdup(p_n);
		}
		*line = ft_strjjoin(*line, c);
	}
	return (0);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
}
