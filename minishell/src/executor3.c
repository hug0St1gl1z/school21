/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:58:58 by rdrizzle          #+#    #+#             */
/*   Updated: 2022/05/12 19:19:30 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

int	ft_callbuiltin(int idx, t_ll_elem *cmd, t_info *info, t_fd *fd)
{
	int		stdcopy[2];
	int		ret;

	stdcopy[0] = dup(STDIN_FILENO);
	stdcopy[1] = dup(STDOUT_FILENO);
	if (remap_fds(fd->fds[0], fd->fds[1]))
	{
		close(stdcopy[0]);
		close(stdcopy[1]);
		return (ft_error(1, "minishell: execbuiltin: remap fds", 1, 0));
	}
	ret = (*info->f_ptrs[idx])(cmd->key, info);
	dup2(stdcopy[0], STDIN_FILENO);
	dup2(stdcopy[1], STDOUT_FILENO);
	close(stdcopy[0]);
	close(stdcopy[1]);
	return (ret);
}
