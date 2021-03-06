/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:47:11 by acristin          #+#    #+#             */
/*   Updated: 2022/03/13 18:06:21 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				pos;
	unsigned char	ch;

	i = 0;
	pos = -1;
	ch = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			pos = i;
		i++;
	}
	if (pos == -1 && ch != '\0')
		return (0);
	if (ch == '\0')
		pos = i;
	return ((char *)s + pos);
}
