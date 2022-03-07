/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:29:07 by aalannys          #+#    #+#             */
/*   Updated: 2021/10/12 16:32:32 by aalannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*temp_next;

	temp = *lst;
	while (temp)
	{
		temp_next = temp->next;
		del(temp->content);
		free(temp);
		temp = temp_next;
	}
	*lst = NULL;
}
