/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:25:28 by cblanca           #+#    #+#             */
/*   Updated: 2021/11/27 16:39:19 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_swich_params(const char params, va_list ap)
{
	if (params == 'd' || params == 'i')
		return (ft_case_d_or_i(ap));
	if (params == 'c')
		return (ft_case_c(ap));
	if (params == 's')
		return (ft_case_s(ap));
	if (params == 'p')
		return (ft_case_p(ap));
	if (params == 'u')
		return (ft_case_u(ap));
	if (params == 'x')
		return (ft_hex_base(va_arg(ap, int),
				"0123456789abcdef"));
	if (params == 'X')
		return (ft_hex_base(va_arg(ap, int),
				"0123456789ABCDEF"));
	if (params == '%')
	{
		ft_putchar_fd(params, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		counter;
	int		count1;
	int		count2;

	counter = 0;
	count1 = 0;
	count2 = 0;
	va_start(ap, str);
	while (str[counter])
	{
		if (str[counter] == '%')
		{
			count1 += ft_swich_params(str[counter + 1], ap);
			counter++;
		}
		else
		{
			ft_putchar_fd(str[counter], 1);
			count2++;
		}
		counter++;
	}
	va_end(ap);
	return (count2 + count1);
}
