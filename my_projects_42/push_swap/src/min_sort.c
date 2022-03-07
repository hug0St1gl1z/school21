/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:03:17 by cblanca           #+#    #+#             */
/*   Updated: 2022/02/23 16:15:45 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// dirty sorting - only for a stack *a (with min, med,max (using swap)) 
void	sort_3(t_stack **a)
{
	if ((*a)->value < (*a)->next->value
		&& (*a)->next->value < (*a)->next->next->value)
		return ;
	if ((*a)->next->value < (*a)->next->next->value
		&& (*a)->next->next->value < (*a)->value)
		return ;
	if ((*a)->next->next->value < (*a)->value
		&& (*a)->value < (*a)->next->value)
		return ;
	s(a, 'a');
}

//the last spin of the stack when min is first & max is last 
// elements of stack *a 
void	final_sort(t_stack **a)
{
	t_stack	*tmp;

	tmp = ft_stackmin(*a);
	if (ft_stacklen(tmp) * 2 < ft_stacklen(*a))
	{
		while ((*a)->value != tmp->value)
			rr(a, 'a');
	}
	else
	{
		while ((*a)->value != tmp->value)
			r(a, 'a');
	}
}

// main sort using score when all elem move in stack *b and push 
// back according to score
t_stack	*sort(t_stack *a, t_stack *b, int argc)
{
	if (argc != 3)
		leave_min_max_med(&a, &b, argc);
	sort_3(&a);
	while (b)
	{
		init_scores(&b);
		count_score(a, &b);
		process_score(&a, &b);
	}
	return (a);
}
