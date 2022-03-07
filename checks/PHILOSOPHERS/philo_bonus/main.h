

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <signal.h>
# include <sys/time.h>
# include <semaphore.h>

# define EXIT_STATUS_EATEN 10
# define EXIT_STATUS_DIED 11

typedef struct s_args
{
	int	n_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_times_to_eat;
}	t_args;

typedef struct s_philosopher
{
	int				id;
	pid_t			pid;
	struct timeval	start_time;
	struct timeval	last_meal_time;
	t_args			*args;
	sem_t			*forks;
	sem_t			*display;
	sem_t			*smb_died;
}	t_philosopher;

void			parse_args(t_args *args, int size, char **arr);

t_philosopher	*create_philosophers_data(t_args *args);
void			free_philo_data(t_philosopher *philo_data, t_args *args);
int				is_died(t_philosopher *data);
void			lock_display_and_die(t_philosopher *data);

void			print_status(t_philosopher *data, char *str, int save_time);
void			take_forks(t_philosopher *data);
void			release_forks(t_philosopher *data);

int				philosopher(t_philosopher *data);
void			*timekeeper(void *arg);

void			monitor(t_philosopher *philo_data, t_args args);

void			launch_philosophers(t_philosopher *philo_data, t_args args);

#endif