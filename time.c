#include "philo.h"

long long	ft_get_time(void)
{
	t_time	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

long long	ft_current_time(t_philo *philo)
{
	long long	time;

	time = ft_get_time() - philo->info->creation_time;
	return (time);
}

int	ft_puterr(char *err)
{
	write(STDERR_FILENO, err, ft_strlen(err));
	return (FT_FAILURE);
}