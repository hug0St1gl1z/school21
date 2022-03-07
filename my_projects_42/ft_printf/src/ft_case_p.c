/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:10:09 by cblanca           #+#    #+#             */
/*   Updated: 2021/11/27 12:27:28 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hex_num(unsigned long p, char *hex_symbols)
{
	int	counter;

	counter = 0;
	if (p >= 16)
		counter = ft_print_hex_num(p / 16, hex_symbols);
	counter++;
	ft_putchar_fd(hex_symbols[p % 16], 1);
	return (counter);
}

int	ft_hex_base(unsigned int ap, char *hex_symbols)
{
	if (ap < 0)
		return (ft_print_hex_num(4294967296 + ap, hex_symbols));
	else
		return (ft_print_hex_num(ap, hex_symbols));
}

int	ft_case_p(va_list ap)
{
	unsigned long	p;
	char			*hex_symbols;

	hex_symbols = "0123456789abcdef";
	p = va_arg(ap, unsigned long);
	ft_putstr_fd("0x", 1);
	return (2 + ft_print_hex_num(p, hex_symbols));
}
