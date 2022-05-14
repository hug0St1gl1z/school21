/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:26:04 by gmckinle          #+#    #+#             */
/*   Updated: 2022/05/12 19:18:31 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "readline/readline.h"
#include "readline/history.h"
#include "minishell.h"
#include "utils.h"

int	ft_destroy(t_info *info)
{
	ft_free_char2dem(info->envp, -1);
	free(info->g_exit_str);
	llist_free(info->envp_list);
	rl_clear_history();
	return (0);
}
