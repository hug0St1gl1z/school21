/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:10:20 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/12 12:31:42 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* копирует num байтов первого блока памяти, на который ссылается указатель
 srcptr, во второй блок памяти, на который ссылается указатель destptr*/

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t		i;

	i = 0;
	if (!d && !s)
		return (NULL);
	while (i < n)
	{
		*((unsigned char *)d + i) = *((unsigned char *)s + i);
		i++;
	}
	return (d);
}
