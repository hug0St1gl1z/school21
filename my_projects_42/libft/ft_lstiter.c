/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:11:49 by cblanca           #+#    #+#             */
/*   Updated: 2021/10/14 15:41:08 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* проходя по списку применяет к каждому элементу функцию */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*elem;

	elem = lst;
	if (!lst)
		return ;
	if (elem -> next)
		ft_lstiter(lst->next, f);
	f(lst->content);
}
