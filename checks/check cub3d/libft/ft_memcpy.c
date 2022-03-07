/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:29:41 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:33:29 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*c_dst;
	const unsigned char	*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (const unsigned char *)src;
	if (!src && !dst)
	{
		return (NULL);
	}
	while (n--)
		*c_dst++ = *c_src++;
	return (dst);
}
