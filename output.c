#include "philo.h"

/* print_status:
*	Prints a philosopher's status in plain text as required by the project
*	subject:
*		timestamp_in_ms X status
*/
static void	print_status(t_philo *philo, char *str)
{
	printf("%ld\t|%d|\t%s\n", get_time_in_ms() - philo->table->start_time,
		philo->id + 1, str);
}

/* write_status:
*	Prints the status of a philosopher as long as the simulation is
*	still active. Locks the write mutex to avoid intertwined messages
*	from different threads.
*/
void	write_status(t_philo *philo, bool reaper_report, t_status status)
{
	pthread_mutex_lock(&philo->table->write_lock);
	if (has_simulation_stopped(philo->table) == true && reaper_report == false)
	{
		pthread_mutex_unlock(&philo->table->write_lock);
		return ;
	}
	if (status == DIED)
		print_status(philo, RED "died " END_COL DEATH_EMOJI);
	else if (status == EATING)
		print_status(philo, "is eating " EATING_EMOJI);
	else if (status == SLEEPING)
		print_status(philo, "is sleeping " SLEEPING_EMOJI);
	else if (status == THINKING)
		print_status(philo, "is thinking " THINKING_EMOJI);
	else if (status == GOT_FORK_1 || status == GOT_FORK_2)
		print_status(philo, "has taken a fork " FORK_EMOJI);
	pthread_mutex_unlock(&philo->table->write_lock);
}
