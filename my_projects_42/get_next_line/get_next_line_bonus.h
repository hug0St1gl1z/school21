/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:43:48 by cblanca           #+#    #+#             */
/*   Updated: 2021/11/27 13:15:40 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX_COUNT
#  define FD_MAX_COUNT 100000
# endif

int			pointer_to_end_line(char *line);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);

/* get_next_line */

char		*get_next_line(int fd);
char		*get_line(int fd, char *line);
char		*line_after_n(char *line);
char		*line_before_n(char *buff);

#endif
