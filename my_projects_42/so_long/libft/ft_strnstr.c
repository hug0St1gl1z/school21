/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:47:07 by acristin          #+#    #+#             */
/*   Updated: 2022/03/13 18:06:16 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t n)
{
	size_t	len_src;

	if (*src == '\0')
		return ((char *)dst);
	len_src = ft_strlen(src);
	while (*dst && n >= len_src)
	{
		if (*dst == *src && ft_memcmp(dst, src, len_src) == 0)
			return ((char *)dst);
		dst++;
		n--;
	}
	return (NULL);
}
