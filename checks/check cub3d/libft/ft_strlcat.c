/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:30:10 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:34:16 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (d_len >= size)
		return (size + s_len);
	if (!s_len)
		return (d_len);
	if (s_len + d_len + 1 <= size)
	{
		ft_memcpy((dst + d_len), src, s_len);
		dst[s_len + d_len] = '\0';
	}
	else
	{
		ft_memcpy((dst + d_len), src, size - d_len);
		dst[size - 1] = '\0';
	}
	return (d_len + s_len);
}
