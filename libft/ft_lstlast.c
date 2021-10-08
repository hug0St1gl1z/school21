/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:08:50 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/08 13:18:13 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_list;

	if (lst == (NULL))
		return (NULL);
	last_list = lst;
	while (last_list -> next)
		last_list = last_list -> next;
	return (last_list);
}
