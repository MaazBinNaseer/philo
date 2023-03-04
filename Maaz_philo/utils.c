// /* print_status_debug:
// *	Prints the philosopher's status in an easier to read,
// *	colorful format to help with debugging. For fork-taking
// *	statuses, extra information is displayed to show which fork
// *	the philosopher has taken.
// */
// static void	print_status_debug(t_philo *philo, char *color,
// 								char *str, t_status status)
// {
// 	if (status == GOT_FORK_1)
// 		printf("[%10ld]\t%s%03d\t%s\e[0m: fork [%d]\n",
// 			get_time_in_ms() - philo->table->start_time,
// 			color, philo->id + 1, str, philo->fork[0]);
// 	else if (status == GOT_FORK_2)
// 		printf("[%10ld]\t%s%03d\t%s\e[0m: fork [%d]\n",
// 			get_time_in_ms() - philo->table->start_time,
// 			color, philo->id + 1, str, philo->fork[1]);
// 	else
// 		printf("[%10ld]\t%s%03d\t%s\e[0m\n",
// 			get_time_in_ms() - philo->table->start_time,
// 			color, philo->id + 1, str);
// }

// /* write_status_debug:
// *	Redirects the status writing for debug mode. For this option,
// *	the DEBUG_FORMATTING option must be set to 1 in philo.h.
// */
// static void	write_status_debug(t_philo *philo, t_status status)
// {
// 	if (status == DIED)
// 		print_status_debug(philo, RED, "died", status);
// 	else if (status == EATING)
// 		print_status_debug(philo, GREEN, "is eating", status);
// 	else if (status == SLEEPING)
// 		print_status_debug(philo, CYAN, "is sleeping", status);
// 	else if (status == THINKING)
// 		print_status_debug(philo, CYAN, "is thinking", status);
// 	else if (status == GOT_FORK_1)
// 		print_status_debug(philo, PURPLE, "has taken a fork", status);
// 	else if (status == GOT_FORK_2)
// 		print_status_debug(philo, PURPLE, "has taken a fork", status);
// }
