/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:04:04 by cblanca           #+#    #+#             */
/*   Updated: 2022/02/20 13:54:51 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	ft_stacklast(*a)->next = tmp;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = NULL;
	ft_stacklast(*b)->next = tmp;
	write(1, "rr\n", 3);
}

void	rr(t_stack **a, char name)
{
	t_stack	*tmp;

	tmp = (*a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*a);
	(*a) = tmp->next;
	tmp->next = NULL;
	write(1, "rr", 2);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	rrab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*a);
	(*a) = tmp->next;
	tmp->next = NULL;
	tmp = (*b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*b);
	(*b) = tmp->next;
	tmp->next = NULL;
	write(1, "rrr\n", 4);
}
