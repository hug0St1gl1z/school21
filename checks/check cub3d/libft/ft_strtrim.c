/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:30:44 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:34:56 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*first;
	char	*last;
	size_t	length;
	char	*trimmed;

	if (!s1)
		return (NULL);
	length = ft_strlen(s1);
	first = (char *)s1;
	last = first + length;
	while (ft_strchr(set, *first) && first < last)
		first++;
	while (ft_strchr(set, *last) && last > first)
		last--;
	trimmed = ft_substr(first, 0, last - first + 1);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}
