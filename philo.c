#include "philo.h"

void	*philosophers(void *arg)
{
	t_philo	*philo;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	while (!philo->should_die && !philo->info->finish)
	{
		right_fork = philo->id;
		left_fork = (philo->id + 1) % philo->info->number_of_philosophers;
		grab_fork(philo, right_fork);
		if (philo->info->number_of_philosophers == 1)
		{
			usleep(1000000);
			break ;
		}
		grab_fork(philo, left_fork);
		ft_eating(philo);
		down_fork(philo, right_fork, left_fork);
		sleep_then_think(philo);
	}
	return (NULL);
}

void	ft_print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->finish_lock);
	if (!philo->info->finish)
		printf("%lli\t%i\t%s\n", ft_current_time(philo), philo->id + 1, msg);
	pthread_mutex_unlock(&philo->info->finish_lock);
}