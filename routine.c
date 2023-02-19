#include "philo.h"

void	down_fork(t_philo *philo, int f1, int f2)
{
	pthread_mutex_unlock(&philo->info->forks[f1]);
	pthread_mutex_unlock(&philo->info->forks[f2]);
}

void	ft_eating(t_philo *philo)
{
	ft_print_msg(philo, "is eating");
	usleep(philo->info->time_to_eat * 1000);
	philo->last_meal = ft_get_time();
	philo->ate++;
	if (philo->ate == philo->info->number_of_times_each_philosopher_must_eat)
		philo->info->all_ate++;
}

void	grab_fork(t_philo *philo, int f)
{
	pthread_mutex_lock(&philo->info->forks[f]);
	ft_print_msg(philo, "has taken a fork");
}

void	sleep_then_think(t_philo *philo)
{
	ft_print_msg(philo, "is sleeping");
	usleep(philo->info->time_to_sleep * 1000);
	ft_print_msg(philo, "is thinking");
}

void	ft_join_free(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
		pthread_join(info->philo[i++].thread, NULL);
	free(info->philo);
	i = 0;
	while (i < info->number_of_philosophers)
		pthread_mutex_destroy(&info->forks[i++]);
	pthread_mutex_destroy(&info->finish_lock);
	free(info->forks);
	free(info);
}