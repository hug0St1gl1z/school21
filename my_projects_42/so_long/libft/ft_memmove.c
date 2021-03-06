/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:45:49 by acristin          #+#    #+#             */
/*   Updated: 2022/03/13 18:04:41 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (n > 0 && (src || dest))
	{
		if (dest > src)
		{
			i = (int)n - 1;
			while (i >= 0)
			{
				*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
				i--;
			}
		}
		else
		{
			i = 0;
			while (i < (int)n)
			{
				*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
				i++;
			}
		}
	}
	return (dest);
}
