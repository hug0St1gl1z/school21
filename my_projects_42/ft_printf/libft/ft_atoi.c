/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:04:55 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/12 09:51:51 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* вспомогательная функция в коментариях не нуждается ) */

static int	ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

/* классическй атои, ищет и выводит первую последовательность 
символов */

int	ft_atoi(const char *str)
{
	int	result;
	int	negative;
	int	i;

	negative = 1;
	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_strlen(&str[i]) > 19 && negative != -1)
			return (-1);
		if (i > 19)
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * negative);
}
