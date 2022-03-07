/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:54:35 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/18 11:03:04 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Возвращает подстроку строки string, начинающейся с start символа по счету
 и длиной length символов */

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*rtn;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	if ((size_t)start > (ft_strlen(s) + 1)) // если 
// 		len = 0;
// 	rtn = malloc(sizeof(char) * (len + 1));
// 	i = 0;
// 	if (!rtn)
// 		return (0);
// 	while (i < len)
// 	{
// 		rtn[i] = *(s + start + i);
// 		i++;
// 	}
// 	rtn[i] = '\0';
// 	return (rtn);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return ((void *)0);
	l = ft_strlen(s);
	if (l < len)
		len = l;
	ret = malloc(len + 1);
	if (!ret)
		return ((void *)0);
	if (start > l)
		len = 0;
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
