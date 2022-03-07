/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:30:33 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:34:47 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_l;
	size_t	i;
	char	*res;

	needle_l = ft_strlen(needle);
	res = (char *)haystack;
	if (needle_l == 0)
		return (res);
	if (!(*haystack))
		return (NULL);
	i = 0;
	while (i + needle_l <= len)
	{
		if (*(res + i) == *needle)
		{
			if (ft_strncmp((res + i), needle, needle_l) == 0)
				return (res + i);
		}
		i++;
	}
	return (NULL);
}
