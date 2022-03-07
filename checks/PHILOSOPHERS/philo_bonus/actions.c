

#include "main.h"

void	print_status(t_philosopher *data, char *str, int save_time)
{
	struct timeval			time;
	int						interval_ms;

	sem_wait(data->display);
	gettimeofday(&time, 0);
	interval_ms = (int)(time.tv_sec - data->start_time.tv_sec) *1000
		+ (int)(time.tv_usec - data->start_time.tv_usec) / 1000;
	printf("%d %d %s\n", interval_ms, data->id, str);
	sem_post(data->display);
	if (save_time)
		data->last_meal_time = time;
}

void	take_forks(t_philosopher *data)
{
	sem_wait(data->forks);
	sem_wait(data->smb_died);
	print_status(data, "has taken a fork", 0);
	sem_post(data->smb_died);
	sem_wait(data->forks);
	sem_wait(data->smb_died);
	print_status(data, "has taken a fork", 0);
	sem_post(data->smb_died);
}

void	release_forks(t_philosopher *data)
{
	sem_post(data->forks);
	sem_post(data->forks);
}
