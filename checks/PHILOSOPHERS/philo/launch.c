#include "main.h"

void	launch_philosophers(t_philosopher *philo_data, t_args args)
{
	pthread_t	thread;
	int			i;

	i = 0;
	while (i < args.n_philosophers)
	{
		if (pthread_create(&thread, NULL, &philosopher,
				(void *)(philo_data + i)))
			exit(1);
		usleep(50);
		pthread_detach(thread);
		i += 2;
		if (i >= args.n_philosophers && i % 2 == 0)
			i = 1;
	}
}
