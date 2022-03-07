/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:31:03 by cblanca           #+#    #+#             */
/*   Updated: 2022/02/23 15:48:57 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// 
void	init_scores(t_stack **b)
{
	t_stack	*tmp;

	tmp = (*b);
	while (tmp)
	{
		tmp->rscore_a = 0;
		tmp->rscore_b = 0;
		tmp->score_a = 0;
		tmp->score_b = 0;
		tmp = tmp->next;
	}
}

void	count_score(t_stack *a, t_stack **b)
{
	t_stack	*tmp;
	int		len;

	tmp = (*b);
	len = ft_stacklen(a);
	count_a_score(a, b, len, ft_stacklast(a)->value);
	count_b_score(b);
	while (tmp)
	{
		tmp = tmp->next;
	}
}

int	min_score(t_stack *el, int min)
{
	if (el->score_a < min && el->score_a >= el->score_b)
		min = el->score_a;
	if (el->rscore_a < min && el->rscore_a >= el->rscore_b)
		min = el->rscore_a;
	if (el->score_b < min && el->score_b >= el->score_a)
		min = el->score_b;
	if (el->rscore_b < min && el->rscore_b >= el->rscore_a)
		min = el->rscore_b;
	if (el->score_a + el->rscore_b < min)
		min = el->score_a + el->rscore_b;
	if (el->rscore_a + el->score_b < min)
		min = el->rscore_a + el->score_b;
	return (min);
}
