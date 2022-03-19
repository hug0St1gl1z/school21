/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:36:22 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/13 16:02:19 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Функция ft_putchar_fd выводит символ в файловый дискриптор fd.*/

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}