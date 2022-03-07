/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:53:43 by cblanca           #+#    #+#             */
/*   Updated: 2022/02/20 14:01:30 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate2(t_stack *tmp, int min, t_stack **a, t_stack **b)
{
	if (tmp->score_a == min && tmp->score_a >= tmp->score_b)
	{
		rotate_sync('f', tmp->score_b, a, b);
		rotate1(r, 'a', min - tmp->score_b, a);
	}
	else if (tmp->score_b == min && tmp->score_b >= tmp->score_a)
	{
		rotate_sync('f', tmp->score_a, a, b);
		rotate1(r, 'b', min - tmp->score_a, b);
	}
	else if (tmp->rscore_a == min && tmp->rscore_a >= tmp->rscore_b)
	{
		rotate_sync('b', tmp->rscore_b, a, b);
		rotate1(rr, 'a', min - tmp->rscore_b, a);
	}
	else if (tmp->rscore_b == min && tmp->rscore_b >= tmp->rscore_a)
	{
		rotate_sync('b', tmp->rscore_a, a, b);
		rotate1(rr, 'b', min - tmp->rscore_a, b);
	}
	else if (tmp->score_a + tmp->rscore_b == min)
		rotate_async(a, b, 'a', tmp);
	else if (tmp->score_b + tmp->rscore_a == min)
		rotate_async(b, a, 'b', tmp);
	p(a, b, 'a');
}

void	rotate1(void f(t_stack **a, char name), char name, int n, t_stack **a)
{
	int	i;

	i = 0;
	while (i < n)
	{
		f(a, name);
		i++;
	}
}

void	rotate_sync(char direct, int n, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (ft_stacklen(*b) == 1 && direct == 'f' && n)
		r(a, 'a');
	else if (ft_stacklen(*b) == 1 && direct == 'b' && n)
		rr(a, 'a');
	else
	{
		while (i < n)
		{
			if (direct == 'f')
				rab(a, b);
			else
				rrab(a, b);
			i++;
		}
	}
}

void	rotate_async(t_stack **a, t_stack **b, char first, t_stack *tmp)
{
	int		i;
	int		na;
	int		nb;
	char	second;

	i = 0;
	second = 'a';
	if (first == 'a')
	{
		na = tmp->score_a;
		nb = tmp->rscore_b;
		second = 'b';
	}
	else
	{
		na = tmp->score_b;
		nb = tmp->rscore_a;
	}
	while (i++ < na)
		r(a, first);
	i = 0;
	while (i++ < nb)
		rr(b, second);
}
