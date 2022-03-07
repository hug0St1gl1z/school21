/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:31:06 by cblanca           #+#    #+#             */
/*   Updated: 2022/02/23 15:52:37 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_b_score(t_stack **b)
{
	int		count;
	int		len;
	t_stack	*tmp;

	count = 0;
	tmp = (*b);
	len = ft_stacklen(*b);
	while (tmp)
	{
		tmp->score_b = count;
		tmp->rscore_b = len - count;
		count++;
		tmp = tmp->next;
	}
}

void	count_a_score(t_stack *a, t_stack **b, int len, int last)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpb = (*b);
	while (tmpb)
	{
		tmpa = a;
		if (tmpb->value < last)
		{
			while (tmpa->value < tmpa->next->value && tmpa->value > last)
			{
				tmpa = tmpa->next;
				tmpb->score_a++;
			}
			tmpa = tmpa->next;
			tmpb->score_a++;
		}
		while (tmpb->value > tmpa->value)
		{
			tmpa = tmpa->next;
			tmpb->score_a++;
		}
		tmpb->rscore_a = len - tmpb->score_a;
		tmpb = tmpb->next;
	}
}

void	process_score(t_stack **a, t_stack **b)
{
	int		min;
	int		min_tmp;
	t_stack	*tmp;
	t_stack	*el;

	min = ft_stacklen(*a) + ft_stacklen(*b);
	el = *b;
	while (el)
	{
		min_tmp = min;
		min = min_score(el, min);
		if (min_tmp != min)
			tmp = el;
		el = el->next;
	}
	rotate2(tmp, min, a, b);
}
