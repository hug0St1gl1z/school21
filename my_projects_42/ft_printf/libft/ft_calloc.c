/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:14:22 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/12 13:18:36 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* выделяет блок памяти для массива размером 
count элементов, каждый из которых занимает   
size байт, и инициализирует все свои биты в нулями.*/

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	result = (char *)malloc(size * count);
	if (result == NULL)
		return (NULL);
	while (i < count * size)
	{
		result[i] = 0;
		++i;
	}
	return (result);
}
