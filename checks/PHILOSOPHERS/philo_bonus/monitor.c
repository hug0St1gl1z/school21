

#include "main.h"

static int	get_exit_status(pid_t pid)
{
	int	status;

	status = 0;
	waitpid(pid, &status, WNOHANG);
	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}
	return (0);
}

void	monitor(t_philosopher *philo_data, t_args args)
{
	int		i;
	int		eaten_philo_count;
	int		status;

	eaten_philo_count = 0;
	while (1)
	{
		i = -1;
		while (++i < args.n_philosophers)
		{
			status = get_exit_status(philo_data[i].pid);
			if (status == EXIT_STATUS_EATEN)
				eaten_philo_count++;
			if (status == EXIT_STATUS_DIED)
			{
				print_status(philo_data + i, "is died", 1);
				free_philo_data(philo_data, &args);
			}
		}
		if (eaten_philo_count == args.n_philosophers)
			free_philo_data(philo_data, &args);
	}
}
