/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:58:55 by cblanca           #+#    #+#             */
/*   Updated: 2021/11/27 12:36:21 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int		a = 1234567890;
	char	b = 120;
	char	*c = "Hello world!";
	char	d[5];
	int		e = 1234567890;
	size_t	f = ULONG_MAX;

	ft_printf("print int      		- %d\n", a);
	printf("main_print char     		- %c\n", b);
	ft_printf("print char     		- %c\n", b);
	ft_printf("print cahr*    		- %s\n", c);
	ft_printf("print p_hex    		- %p\n", d);
	ft_printf("print uns_int  		- %u\n", e);
	printf("main_print hex_long_max 	- %x\n", f);
	ft_printf("print hex_long_max 	- %x\n", f);
	
}
