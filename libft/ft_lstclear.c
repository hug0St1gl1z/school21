/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:42:42 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/08 13:55:39 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*elem_emp;

	if (lst != NULL)
	{
		elem = *lst;
		while (elem != NULL)
		{
			del(elem -> content);
			elem_emp = elem;
			elem = elem -> next;
			free(elem_emp);
		}
		*lst = NULL;
	}
}
