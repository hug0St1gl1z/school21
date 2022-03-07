

#include "main.h"

static void	unlink_semaphores(void)
{
	sem_unlink("fork");
	sem_unlink("philo_display");
	sem_unlink("philo_smb_died");
}

t_philosopher	*create_philosophers_data(t_args *args)
{
	t_philosopher	*philo_data;
	sem_t			*forks;
	sem_t			*display;
	sem_t			*smb_died;
	int				i;

	philo_data = malloc(args->n_philosophers * sizeof(*philo_data));
	if (philo_data == 0)
		return (0);
	unlink_semaphores();
	forks = sem_open("fork", O_CREAT | O_EXCL, S_IRWXU, args->n_philosophers);
	display = sem_open("philo_display", O_CREAT | O_EXCL, S_IRWXU, 1);
	smb_died = sem_open("philo_smb_died", O_CREAT | O_EXCL, S_IRWXU, 1);
	i = -1;
	while (++i < args->n_philosophers)
	{
		philo_data[i].id = i + 1;
		gettimeofday(&philo_data[i].start_time, 0);
		philo_data[i].last_meal_time = philo_data[i].start_time;
		philo_data[i].args = args;
		philo_data[i].forks = forks;
		philo_data[i].display = display;
		philo_data[i].smb_died = smb_died;
	}
	return (philo_data);
}

void	free_philo_data(t_philosopher *philo_data, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philosophers)
		kill(philo_data[i].pid, SIGKILL);
	free(philo_data);
	exit(0);
}

int	is_died(t_philosopher *data)
{
	struct timeval	time;
	int				interval_ms;

	gettimeofday(&time, 0);
	interval_ms = (int)(time.tv_sec - data->last_meal_time.tv_sec) *1000
		+ (int)(time.tv_usec - data->last_meal_time.tv_usec) / 1000;
	if (interval_ms > data->args->time_to_die)
		return (1);
	return (0);
}

void	lock_display_and_die(t_philosopher *data)
{
	sem_wait(data->smb_died);
	exit(EXIT_STATUS_DIED);
}
