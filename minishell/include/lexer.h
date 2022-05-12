/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:17:46 by cblanca           #+#    #+#             */
/*   Updated: 2022/05/12 19:17:48 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define LX_SEP				0
# define LX_WORD			1
# define LX_PARN_L			2
# define LX_PARN_R			3
# define LX_FIELD			4
# define LX_IF_OR			5
# define LX_IF_AND			6
# define LX_REDIR_OUT		7
# define LX_REDIR_IN		8
# define LX_REDIR_APPEND	9
# define LX_REDIR_SOURCE	10
# define LX_EXP_FIELD		11
# define LX_PIPE			12
# define LX_NCONST			13

# include "linked_list.h"

int				_lx_is_special(const char c);
int				_lx_case_word(t_llist *tokens, const char *line,
					unsigned long i, unsigned long *t);
int				_lx_case_metachar(t_llist *tokens, const char *line,
					unsigned long i, unsigned long *t);
int				_lx_case_quotes(t_llist *tokens, const char *line,
					unsigned long i, unsigned long *t);
int				lx_lexer(t_llist *tokens, const char *line);

#endif
