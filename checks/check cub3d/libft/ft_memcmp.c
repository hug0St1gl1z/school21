/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:29:39 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:33:26 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c_s1;
	const unsigned char	*c_s2;
	size_t				i;

	c_s1 = (const unsigned char *)s1;
	c_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (c_s1[i] - c_s2[i])
			return (c_s1[i] - c_s2[i]);
		i++;
	}
	return (0);
}
