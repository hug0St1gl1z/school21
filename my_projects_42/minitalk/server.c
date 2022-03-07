/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:35:30 by cblanca           #+#    #+#             */
/*   Updated: 2022/01/12 19:00:01 by cblanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	int					error_flag;
	struct sigaction	sig;

	error_flag = 0;
	ft_memset(&sig, 0, sizeof(sig));
	sigemptyset(&sig.sa_mask);
	sig.sa_sigaction = compose_bite;
	sig.sa_flags = SA_SIGINFO;
	print_pid();
	while (1 && error_flag == 0)
	{
		error_flag = sigaction(SIGUSR1, &sig, NULL);
		error_flag = sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	if (error_flag == -1)
		write(1, "Server: Error in sigaction\n", 27);
	return (1);
}

void	print_pid(void)
{
	int	pid;

	pid = getpid();
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}

void	compose_bite(int signal_num, siginfo_t *info, void *old_info)
{
	static int	bits;
	static char	c;
	int			check_error;

	(void)old_info;
	check_error = 0;
	if (signal_num == SIGUSR1)
		c = c | 0 << bits;
	else
		c = c | 1 << bits;
	bits++;
	if (bits == 8)
		print_bite(&bits, &c, info);
	check_error = kill(info->si_pid, SIGUSR1);
	if (check_error == -1)
		write(2, "Server: Error in signal transfer\n", 33);
}

void	print_bite(int *bits, char *c, siginfo_t *info)
{
	int	check_error;

	check_error = 0;
	if (*c == '\0')
	{
		write(1, "\n", 1);
		check_error = kill(info->si_pid, SIGUSR2);
		if (check_error == -1)
			write(2, "Server: Error in signal transfer \n", 33);
	}
	else
		write(1, c, 1);
	*bits = 0;
	*c = 0;
}
