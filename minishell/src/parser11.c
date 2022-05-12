/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser11.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:43:54 by rdrizzle          #+#    #+#             */
/*   Updated: 2022/05/12 19:22:30 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "lexer.h"

void	_prs_only_empty_var(t_llist *str, char **word, t_expi *ei)
{
	t_ll_elem	*h;

	if (ei->size == 0)
	{
		h = str->head;
		while (h)
		{
			if ((int)h->key != LX_WORD)
				return ;
			h = h->next;
		}
		free(*word);
		*word = NULL;
	}
}
