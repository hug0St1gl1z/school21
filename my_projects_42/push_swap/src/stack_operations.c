/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:54:02 by cblanca           #+#    #+#             */
/*   Updated: 2022/02/20 14:03:45 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (0);
	res->value = value;
	res->next = NULL;
	return (res);
}

int	ft_stacklen(t_stack *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		(*lst) = new;
	else
		ft_stacklast(*lst)->next = new;
}

t_stack	*ft_stackmin(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	if (tmp->value < ft_stacklast(tmp)->value)
		return (tmp);
	while (tmp->value < tmp->next->value)
		tmp = tmp->next;
	return (tmp->next);
}
