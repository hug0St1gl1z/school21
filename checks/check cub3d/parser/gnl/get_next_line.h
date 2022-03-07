/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:00:29 by namina            #+#    #+#             */
/*   Updated: 2022/01/29 18:00:30 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_set_fd
{
	char	*str;
	int		fd;
	void	*next;
	int		read_res;
}			t_set_fd;

char		*ft_strdup_gnl(char *src, int len, int offset);
char		*ft_strjoin_gnl(char *s1, char *s2, int len);
int			ft_strlen_gnl(const char *s);
t_set_fd	*get_current_el(t_set_fd **list, int fd);
void		lst_free(t_set_fd **list);

#endif