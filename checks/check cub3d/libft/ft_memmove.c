/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:29:44 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:33:33 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*c_dst;
	const unsigned char	*c_src;

	c_dst = (unsigned char *)dest;
	c_src = (const unsigned char *)src;
	if (n == 0 || (!src && !dest))
		return (dest);
	if (c_dst < c_src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			*(c_dst + n) = *(c_src + n);
	}
	return (dest);
}
