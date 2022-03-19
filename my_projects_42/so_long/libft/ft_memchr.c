/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:45:37 by acristin          #+#    #+#             */
/*   Updated: 2022/03/13 18:04:21 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	void			*p;
	unsigned char	ch;

	i = 0;
	p = (void *)s;
	ch = (unsigned char) c;
	while (i < n)
	{
		if (*(unsigned char *)(p + i) == ch)
			return (p + i);
		i++;
	}
	return (0);
}
