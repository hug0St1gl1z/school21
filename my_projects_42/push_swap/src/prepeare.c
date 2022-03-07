/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepeare.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:12:49 by cblanca           #+#    #+#             */
/*   Updated: 2022/02/20 13:58:12 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min(t_stack *a)
{
	int		min;

	min = a->value;
	while (a->next)
	{
		a = a->next;
		if (a->value < min)
			min = a->value;
	}
	return (min);
}

int	max(t_stack *a)
{
	int		max;

	max = a->value;
	while (a->next)
	{
		a = a->next;
		if (a->value > max)
			max = a->value;
	}
	return (max);
}

int	med(t_stack *a)
{
	int		more;
	int		less;
	t_stack	*tmpi;
	t_stack	*tmpj;

	tmpi = a;
	while (tmpi->value != ft_stacklast(a)->value)
	{
		more = 0;
		less = 0;
		tmpj = a;
		while (tmpj->value != ft_stacklast(a)->value)
		{
			if (tmpi->value < tmpj->value)
				more++;
			if (tmpi->value > tmpj->value)
				less++;
			tmpj = tmpj->next;
		}
		if (more == less || more == less + 1)
			return (tmpi->value);
		tmpi = tmpi->next;
	}
	return (0);
}

void	leave_min_max_med(t_stack **a, t_stack **b, int argc)
{
	int		imin;
	int		imax;
	int		imed;
	int		i;

	i = 0;
	imin = min(*a);
	imax = max(*a);
	imed = med(*a);
	if (ft_stacklast(*a)->value != imin && ft_stacklast(*a)->value != imax
		&& ft_stacklast(*a)->value != imed)
	{
		rr(a, 'a');
		p(b, a, 'b');
	}
	while (i++ < argc)
	{
		if (ft_stacklen(*a) == 3)
			return ;
		if ((*a)->value == imin || (*a)->value == imax
			|| (*a)->value == imed)
			r(a, 'a');
		else
			p(b, a, 'b');
	}
}
