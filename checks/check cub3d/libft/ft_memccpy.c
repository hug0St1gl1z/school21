/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:29:34 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:33:17 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		u_c;
	const unsigned char	*c_src;
	unsigned char		*c_dst;	

	u_c = (unsigned char)c;
	c_src = (const unsigned char *)src;
	c_dst = (unsigned char *)dst;
	if (!src && !dst)
		return (NULL);
	while (n--)
	{
		*c_dst++ = *c_src;
		if (*c_src == u_c)
			return (c_dst);
		c_src++;
	}
	return (NULL);
}
