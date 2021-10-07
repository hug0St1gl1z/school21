/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:09:15 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/07 12:59:06 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*des;
	size_t	len;

	len = ft_strlen(s) + 1;
	des = malloc(sizeof(char) * len);
	if (!des)
		return (0);
	des = ft_memcpy(des, s, len);
	return (des);
}
