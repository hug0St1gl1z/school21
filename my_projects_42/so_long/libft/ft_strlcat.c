/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:46:46 by acristin          #+#    #+#             */
/*   Updated: 2022/03/13 18:05:47 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dsize;

	dsize = 0;
	while (dst[dsize] != '\0' && dsize < size)
		dsize++;
	i = dsize;
	while (src[dsize - i] != '\0' && dsize + 1 < size)
	{
		dst[dsize] = src[dsize - i];
		dsize++;
	}
	if (i < size)
		dst[dsize] = '\0';
	return (i + ft_strlen(src));
}
