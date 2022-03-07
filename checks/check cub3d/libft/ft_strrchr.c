/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:30:37 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:34:50 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*chr;
	char	sym;

	sym = (char)c;
	len = ft_strlen(s);
	chr = (char *)s;
	while (len > 0)
	{
		if (sym == *(chr + len))
			return (chr + len);
		len--;
	}
	if (sym == *(chr + len))
		return (chr + len);
	return (NULL);
}
