

#include "main.h"

void	launch_philosophers(t_philosopher *philo_data, t_args args)
{
	pthread_t	thread;
	int			i;

	i = 0;
	while (i < args.n_philosophers)
	{
		philo_data[i].pid = fork();
		if (philo_data[i].pid == 0)
		{
			if (pthread_create(&thread, NULL, &timekeeper,
					(void *)(philo_data + i)))
				exit(EXIT_STATUS_DIED);
			pthread_detach(thread);
			philosopher(philo_data + i);
		}
		usleep(50);
		i += 2;
		if (i >= args.n_philosophers && i % 2 == 0)
			i = 1;
	}
}
