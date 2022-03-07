#include "main.h"
#include <limits.h>

static int	ft_atoi(const char *str)
{
	long int	num;
	int			i;
	int			minus;

	minus = 0;
	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			minus = 1;
	i--;
	while (str[++i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		if (minus && - num < INT_MIN)
			return (-1);
		if (!minus && num > INT_MAX)
			return (0);
	}
	if (minus)
		return ((int)(-num));
	return ((int)(num));
}

void	parse_args(t_args *args, int size, char **arr)
{
	args->n_philosophers = ft_atoi(arr[0]);
	args->time_to_die = ft_atoi(arr[1]);
	args->time_to_eat = ft_atoi(arr[2]);
	args->time_to_sleep = ft_atoi(arr[3]);
	if (args->n_philosophers <= 0)
		printf("Error: invalid number of philosophers.\n");
	if (args->time_to_die <= 0 || args->time_to_eat <= 0
		|| args->time_to_sleep <= 0)
		printf("Error: invalid time.\n");
	if (args->n_philosophers <= 0 || args->time_to_die <= 0
		|| args->time_to_eat <= 0 || args->time_to_sleep <= 0)
		exit(1);
	if (size > 4)
		args->n_times_to_eat = ft_atoi(arr[4]);
	else
		args->n_times_to_eat = -1;
}
