/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:40:18 by cblanca           #+#    #+#             */
/*   Updated: 2021/11/26 16:04:38 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_unsigned_putnbr_fd(n / 10, fd);
		ft_unsigned_putnbr_fd(n % 10, fd);
	}
}

int	ft_case_u(va_list ap)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	ft_unsigned_putnbr_fd(i, 1);
	return (ft_numlen(i));
}
