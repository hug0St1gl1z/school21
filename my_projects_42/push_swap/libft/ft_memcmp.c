/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:10:27 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/12 10:29:30 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Функция сравнивает первые num байтов строк s1 и s2. 
Возвращаемое значение 0 если блоки равны, и значение 
отличное от 0, если  блоки не равны. */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(const unsigned char *)(s1 + i) != *(const unsigned char
					*)(s2 + i))
			return (*(const unsigned char *)(s1 + i) - *(const unsigned char
					*)(s2 + i));
		i++;
	}
	return (0);
}
