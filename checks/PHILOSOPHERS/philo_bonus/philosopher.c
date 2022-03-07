

#include "main.h"

int	philosopher(t_philosopher *data)
{
	int	i;

	i = -1;
	while (++i < data->args->n_times_to_eat || data->args->n_times_to_eat == -1)
	{
		take_forks(data);
		if (is_died(data))
			lock_display_and_die(data);
		sem_wait(data->smb_died);
		print_status(data, "is eating", 1);
		sem_post(data->smb_died);
		usleep(data->args->time_to_eat * 1000);
		if (is_died(data))
			lock_display_and_die(data);
		release_forks(data);
		sem_wait(data->smb_died);
		print_status(data, "is sleeping", 0);
		sem_post(data->smb_died);
		usleep(data->args->time_to_sleep * 1000);
		sem_wait(data->smb_died);
		print_status(data, "is thinking", 0);
		sem_post(data->smb_died);
	}
	exit(EXIT_STATUS_EATEN);
}

void	*timekeeper(void *arg)
{
	t_philosopher	*data;

	data = (t_philosopher *)arg;
	while (1)
	{
		usleep(1000);
		if (is_died(data))
			lock_display_and_die(data);
	}
	return (0);
}
