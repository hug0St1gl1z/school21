/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_d_or_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:39:51 by cblanca           #+#    #+#             */
/*   Updated: 2021/11/27 11:24:03 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_numlen(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int	ft_case_d_or_i(va_list ap)
{
	int		num;
	int		numlen;
	char	*str;

	num = va_arg(ap, int);
	numlen = num;
	str = ft_itoa(num);
	ft_putstr_fd(str, 1);
	free(str);
	return (ft_numlen(num));
}
