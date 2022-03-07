/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:02:52 by cblanca           #+#    #+#             */
/*   Updated: 2022/02/20 13:55:34 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_mass(int size, char **mas)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(mas[i]);
		i++;
	}
}

void	warning(int code, char *mess)
{
	write(1, mess, ft_strlen(mess));
	exit(code);
}
