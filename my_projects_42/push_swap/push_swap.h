/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:50:05 by cblanca           #+#    #+#             */
/*   Updated: 2022/02/22 20:24:44 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// library
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

// typedef struct - stack named type - t_stack
typedef struct s_stack
{
	int					score_a;
	int					rscore_a;
	int					score_b;
	int					rscore_b;
	int					value;
	struct s_stack		*next;
}						t_stack;

typedef struct s_flags
{
	int	debug;
	int	color;
}	t_flags;

//push_swap.c
void					push_swap(int argc, char **argv);

// stack_operations.c
t_stack					*ft_stacknew(int value);
t_stack					*ft_stacklast(t_stack *lst);
t_stack					*ft_stackmin(t_stack *a);
void					ft_stackadd_back(t_stack **lst, t_stack *new);
int						ft_stacklen(t_stack *a);

// args_operations.c
int						check_args(int argc, char **argv);
int						check_if_not_final_sorted(int argc, char **argv);

// The_rules_1.c
void					rab(t_stack **a, t_stack **b);
void					rr(t_stack **a, char name);
void					rrab(t_stack **a, t_stack **b);

// The_rules_2.c
void					s(t_stack **a, char name);
void					p(t_stack **a, t_stack **b, char name);
void					r(t_stack **a, char name);

// utils.c
void					warning(int code, char *message);
void					free_mass(int argc, char **argv);

//score_1.c
void					count_b_score(t_stack **b);
void					count_a_score(t_stack *a, t_stack **b, int ln, int lst);
void					process_score(t_stack **a, t_stack **b);

//score_2.c
void					init_scores(t_stack **b);
void					count_score(t_stack *a, t_stack **b);
int						min_score(t_stack *el, int min);

//min_sort.c
void					sort_3(t_stack **a);
void					final_sort(t_stack **a);
t_stack					*sort(t_stack *a, t_stack *b, int argc);

//prepeare.c
int						min(t_stack *a);
int						max(t_stack *a);
int						med(t_stack *a);
void					leave_min_max_med(t_stack **a, t_stack **b, int argc);

//rotate.c

void					rotate_sync(char dir, int n, t_stack **a, t_stack **b);
void					rotate_async(t_stack **a, t_stack **b, char first,
							t_stack *tmp);
void					rotate2(t_stack *tmp, int min, t_stack **a,
							t_stack **b);
void					rotate1(void f(t_stack **a, char name), char name,
							int n, t_stack **a);

// checker folder
int						ft_isdigit_minus_i(int c, int *i);
int						process_command(t_list **a, t_list **b, char *command);
#endif