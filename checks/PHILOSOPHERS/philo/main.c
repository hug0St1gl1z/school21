#include "main.h"

int	main(int argc, char **argv)
{
	t_args			args;
	t_philosopher	*philo_data;

	if (argc < 5 || argc > 6)
		return (1);
	parse_args(&args, argc - 1, argv + 1);
	philo_data = create_philosophers_data(&args);
	create_death_mutex(philo_data, &args);
	if (philo_data == 0)
		return (1);
	launch_philosophers(philo_data, args);
	monitor(philo_data, args);
	return (0);
}
