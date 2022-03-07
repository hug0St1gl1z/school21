/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:29:36 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:33:21 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	u_c;
	unsigned char	*c_s;
	size_t			i;

	c_s = (unsigned char *)s;
	u_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (c_s[i] == u_c)
			return (c_s + i);
		i++;
	}
	return (NULL);
}
