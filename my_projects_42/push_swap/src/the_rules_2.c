/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rules_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:40:09 by cblanca           #+#    #+#             */
/*   Updated: 2022/02/20 13:55:09 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	p(t_stack **a, t_stack **b, char name)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	write(1, "p", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	r(t_stack **a, char name)
{
	t_stack	*tmp;

	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	ft_stacklast(*a)->next = tmp;
	write(1, "r", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	s(t_stack **a, char name)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "s", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}
