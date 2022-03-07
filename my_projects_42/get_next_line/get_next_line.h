/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:43:48 by cblanca           #+#    #+#             */
/*   Updated: 2022/02/12 13:25:29 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* utils */

int			pointer_to_end_line(char *line);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);

/* get_next_line */

char		*get_next_line(int fd);
char		*get_line(int fd, char *line);
char		*line_ater_n(char *line);
char		*line_before_n(char *buff);

#endif
