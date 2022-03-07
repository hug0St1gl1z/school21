/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjothos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:16:11 by cjothos           #+#    #+#             */
/*   Updated: 2021/12/21 22:38:24 by cjothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_fds[2][2];

static char	*get_home(t_prompt prompt)
{
	char	*temp;
	char	*pwd;
	char	*home;

	pwd = getcwd(NULL, 0);
	home = mini_getenv("HOME", prompt.envp, 4);
	if (home && home[0] && ft_strnstr(pwd, home, ft_strlen(pwd)))
	{
		temp = pwd;
		pwd = ft_strjoin("~", &pwd[ft_strlen(home)]);
		free(temp);
	}
	free(home);
	home = ft_strjoin(NULL, pwd);
	free(pwd);
	pwd = ft_strjoin(home, " ");
	free(home);
	home = ft_strjoin(" ", pwd);
	free(pwd);
	pwd = ft_strjoin(home, NULL);
	free(home);
	return (pwd);
}

static char	*get_user(t_prompt prompt)
{
	char	**user;
	char	*temp;

	user = NULL;
	temp = NULL;
	exec_custom(&user, "/usr/bin/whoami", "whoami", prompt.envp);
	if (!user)
		user = ft_extend_matrix(user, "guest");
	temp = ft_strjoin(temp, *user);
	ft_free_matrix(&user);
	return (temp);
}

char	*mini_getprompt(t_prompt prompt)
{
	char	*temp;
	char	*aux;
	char	*temp2;

	temp = get_user(prompt);
	temp2 = ft_strjoin(temp, "@minishell");
	free(temp);
	aux = get_home(prompt);
	temp = ft_strjoin(temp2, aux);
	free(aux);
	free(temp2);
	temp2 = ft_strjoin(temp, NULL);
	free(temp);
	temp = ft_strjoin(temp2, "$ ");
	free(temp2);
	temp2 = ft_strjoin(temp, NULL);
	free(temp);
	return (temp2);
}

void	readline_child(t_prompt *prompt, char *str, char *out, int is_null)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	close(g_fds[0][READ_END]);
	close(g_fds[1][READ_END]);
	out = readline(str);
	write(g_fds[0][WRITE_END], out, ft_strlen(out));
	is_null = !out;
	write(g_fds[1][WRITE_END], &prompt->e_status, sizeof(int));
	free(out);
	close(g_fds[0][WRITE_END]);
	close(g_fds[1][WRITE_END]);
	exit(is_null);
}

char	*mini_readline(t_prompt *prompt, char *str)
{
	pid_t	pid;
	int		is_null;
	char	*out;

	is_null = 0;
	out = NULL;
	if (!mini_here_fd(prompt, g_fds[0], g_fds[1]))
		return (NULL);
	pid = fork();
	if (pid == -1)
		mini_perror(prompt, FORKERR, NULL);
	if (!pid)
		readline_child(prompt, str, out, is_null);
	close(g_fds[0][WRITE_END]);
	close(g_fds[1][WRITE_END]);
	waitpid(pid, &is_null, 0);
	out = get_next_line(g_fds[0][READ_END]);
	if (!is_null && !out)
		out = ft_strdup("");
	read(g_fds[1][READ_END], &prompt->e_status, sizeof(int));
	close(g_fds[0][READ_END]);
	close(g_fds[1][READ_END]);
	return (out);
}
