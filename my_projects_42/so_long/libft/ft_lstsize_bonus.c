/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:45:34 by acristin          #+#    #+#             */
/*   Updated: 2022/03/13 18:04:15 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		count;

	if (!lst)
		return (0);
	count = 1;
	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
