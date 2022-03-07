/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:30:06 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:34:06 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	size_t		str_size;
	char		*cpy_ptr;
	size_t		i;

	if (!src)
		return (NULL);
	i = 0;
	str_size = ft_strlen(src);
	cpy_ptr = malloc(str_size + 1);
	if (!cpy_ptr)
		return (NULL);
	while (i < str_size)
	{
		cpy_ptr[i] = src[i];
		i++;
	}
	cpy_ptr[i] = '\0';
	return (cpy_ptr);
}
