/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:43:36 by cblanca           #+#    #+#             */
/*   Updated: 2021/11/27 12:31:07 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int				ft_printf(const char *str, ...);
int				ft_case_d_or_i(va_list ap);
int				ft_case_c(va_list ap);
int				ft_case_s(va_list ap);
int				ft_case_p(va_list ap);
int				ft_case_u(va_list ap);
int				ft_numlen(long num);
int				ft_print_hex_num(unsigned long p, char *hex_symbols);
int				ft_hex_base(unsigned int ap, char *hex_symbols);

#endif