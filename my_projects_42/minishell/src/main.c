/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:32:20 by rdrizzle          #+#    #+#             */
/*   Updated: 2022/05/12 19:20:33 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "readline/readline.h"
#include "readline/history.h"
#include "minishell.h"
#include "utils.h"
#include "lexer.h"
#include "parser.h"

static char	*_ft_readline(const char *prompt)
{
	char	*line;

	line = readline(prompt);
	if (line && *line)
		add_history(line);
	return (line);
}

void	_main_pre(t_llist **tokens, char **line, char *argv[], int argc)
{
	(void)argv;
	(void)argc;
	signal(SIGINT, handler);
	errno = 0;
	*tokens = llist_new(llist_int_kcmp, NULL, free);
	*line = _ft_readline(MINIS_PROMPT);
}

void	_main_post(t_llist *tokens)
{
	llist_free(tokens);
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_info	info;
	t_llist	*tokens;

	if (ft_init(&info, envp))
		return (EXIT_FAILURE);
	while (info.exit_f)
	{
		_main_pre(&tokens, &line, argv, argc);
		if (line && *line)
		{
			if (lx_lexer(tokens, line) == 0)
				prs_parse(tokens, &info);
			free(line);
		}
		else if (line == NULL)
			info.exit_f = 0;
		_main_post(tokens);
	}
	write(STDOUT_FILENO, "exit\n", 5);
	ft_destroy(&info);
	return (g_exit);
}
