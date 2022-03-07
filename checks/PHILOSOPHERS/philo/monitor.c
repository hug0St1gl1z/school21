#include "main.h"

void	monitor(t_philosopher *philo_data, t_args args)
{
	int	i;
	int	eaten_philo_count;

	while (1)
	{
		usleep(1000);
		eaten_philo_count = 0;
		i = -1;
		while (++i < args.n_philosophers)
		{
			eaten_philo_count += philo_data[i].eaten_n_times;
			if (is_died(philo_data + i) && !philo_data[i].eaten_n_times)
			{
				print_status(philo_data + i, "is died", 1);
				pthread_mutex_lock(philo_data->someone_died);
				free_philo_data(philo_data, &args);
			}
		}
		if (eaten_philo_count == args.n_philosophers)
			free_philo_data(philo_data, &args);
	}
}
