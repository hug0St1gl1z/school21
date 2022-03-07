/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:28:56 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:32:21 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	find_num_len(int num)
{
	size_t	str_size;

	str_size = 0;
	if (num <= 0)
		str_size++;
	while (num != 0)
	{
		str_size++;
		num /= 10;
	}
	return (str_size);
}

char	*ft_itoa(int n)
{
	char			*result;
	char			*start;
	size_t			len;
	unsigned int	u_n;

	len = find_num_len(n) + 1;
	result = malloc(len);
	if (!result)
		return (NULL);
	start = result;
	result[len - 1] = '\0';
	if (n == 0)
		result[0] = '0';
	u_n = n;
	if (n < 0)
	{
		u_n = n * (-1);
		result[len - 2] = '-';
	}
	while (u_n != 0)
	{
		*result++ = (u_n % 10) + '0';
		u_n /= 10;
	}
	return (ft_strrev(start));
}
