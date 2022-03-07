/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:09:02 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/22 13:51:50 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>
#include <stdio.h>                       /* для printf() */

/* копирует из строки src в буфер dst не более чем size - 
символов и гарантированно устанавливает в конец строки нулевой символ */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dstsize)
		return (strlen(src));
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (strlen(src));
}

int	main(void)
{
	const char	*str = "1234567890";
	size_t		sz;
	char		g_buf[30];

	printf("строка: \"%s\"\n\n", str);
	printf("буфер перед копированием: %s", g_buf);
	sz = ft_strlcpy(&g_buf[1], str, sizeof(g_buf));
	if (sz >= sizeof(g_buf))
		printf("обнаружено усечение строки с %zu до %lu символов !\n",
			sz, sizeof(g_buf) - 1);
	printf("буфер после копирования:  \"%s\"\n", g_buf);
	return (0);
}
