/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:09:15 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/12 12:15:00 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* делаем копию строки \0 в куче, используя 
маллок и возвращающая указатель на неё.*/

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*res;

	i = 0;
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = s[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
