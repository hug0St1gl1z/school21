#include "main.h"

int	create_death_mutex(t_philosopher *philo_data, t_args *args)
{
	pthread_mutex_t	*someone_died;
	int				i;

	someone_died = malloc(sizeof(*someone_died));
	if (someone_died == 0)
		return (0);
	pthread_mutex_init(someone_died, 0);
	i = -1;
	while (++i < args->n_philosophers)
		philo_data[i].someone_died = someone_died;
	return (1);
}

t_philosopher	*create_philosophers_data(t_args *args)
{
	t_philosopher	*philo_data;
	pthread_mutex_t	*forks;
	int				i;

	philo_data = malloc(args->n_philosophers * sizeof(*philo_data));
	forks = malloc(args->n_philosophers * sizeof(*forks));
	if (philo_data == 0 || forks == 0)
		return (0);
	i = -1;
	while (++i < args->n_philosophers)
	{
		philo_data[i].id = i + 1;
		philo_data[i].eaten_n_times = 0;
		gettimeofday(&philo_data[i].start_time, 0);
		philo_data[i].last_meal_time = philo_data[i].start_time;
		philo_data[i].args = args;
		if (pthread_mutex_init(forks + i, 0) != 0)
			return (0);
		philo_data[i].left_fork = forks + i;
	}
	i = 0;
	while (++i < args->n_philosophers)
		philo_data[i - 1].right_fork = forks + i;
	philo_data[args->n_philosophers - 1].right_fork = forks;
	return (philo_data);
}

void	free_philo_data(t_philosopher *philo_data, t_args *args)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(philo_data[0].someone_died);
	while (++i < args->n_philosophers)
		pthread_mutex_destroy(philo_data[i].left_fork);
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
