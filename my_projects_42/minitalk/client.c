/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:37:15 by cblanca           #+#    #+#             */
/*   Updated: 2022/01/12 18:52:20 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	struct sigaction	sig2;
	int					error_flag;
	int					len;

	ft_memset(&sig2, 0, sizeof(sig2));
	sigemptyset(&sig2.sa_mask);
	sig2.sa_sigaction = server_answered;
	sig2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig2, NULL);
	sigaction(SIGUSR2, &sig2, NULL);
	error_flag = 0;
	if (argc == 3)
	{
		len = ft_strlen(argv[2]) + 1;
		while (len-- > 0 && error_flag == 0)
			error_flag = push_char(ft_atoi(argv[1]), *argv[2]++);
		if (error_flag == -1)
			write(2, "Client: Error in transfer\n", 26);
	}
	else
		write(2, "Wrong arguments.\n", 17);
	return (0);
}

int	push_char(pid_t pid, char c)
{
	int	bit_move;
	int	error_flag;

	bit_move = -1;
	error_flag = 0;
	while (++bit_move < 8)
	{
		if ((c >> bit_move) & 1)
			error_flag = kill(pid, SIGUSR2);
		else
			error_flag = kill(pid, SIGUSR1);
		if (error_flag == -1)
			break ;
		usleep(30000);
	}
	return (error_flag);
}

void	server_answered(int signal_num, siginfo_t *info, void *old_info)
{
	(void)old_info;
	(void)info;
	if (signal_num == SIGUSR2)
		write(1, "Message received\n", 17);
	else
		(void)signal_num;
}
