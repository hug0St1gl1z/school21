/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:15:22 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/12 09:51:49 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* вспомогательная - счетчик количества знаков */

static int	ft_nlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len = 2;
	while (n / 10)
	{
		n /= 10;
		++len;
	}
	return (len);
}

/* превращаем входящее числовое значение в строку с учетом
префикса */

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_nlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		i = 1;
	}
	str[len] = 0;
	while (len - 1 >= i)
	{
		if (n < 0)
			str[len - 1] = -1 * (n % 10) + '0';
		else
			str[len - 1] = (n % 10) + '0';
		n = n / 10;
		--len;
	}
	return (str);
}
