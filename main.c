#include "header.h"

// void function_call(t_parameters *param)
// {
// 	struct timeval	start;
// 	struct timeval	end;
// 	long			value;

// 	gettimeofday(&start, NULL);
// 	printf("i have called this function\n");
// 	gettimeofday(&end, NULL);
// 	printf("in seconds: %ld\n", (end.tv_sec - start.tv_sec));
// 	printf("%d\n%d\n%d\n%d\n%d\n", param->number_of_philosophers, param->time_to_die, param->time_to_eat, param->time_to_sleep, param->must_eat);
// 	printf("in microseconds: %d\n", (end.tv_usec - start.tv_usec));
// }

void *philo_routine(void *ptr)
{
	t_philosopher *philo;
	philo = (t_philosopher *)ptr;

	printf("philo: %d is thinking\n", philo->philo_id);
	printf("philo: %d right fork: %d\n", philo->philo_id, philo->right_fork);
	printf("philo: %d left fork: %d\n", philo->philo_id, philo->left_fork);
	return (NULL);
}

void create_philos_threads(t_parameters *ptr)
{
	t_philosopher philos[ptr->number_of_philosophers];
	int	i;

	philos->param = ptr;
	i = 0;
	while(i < ptr->number_of_philosophers)
	{
		philos[i].philo_id = i;
		philos[i].left_fork = i;
		philos[i].right_fork = (i - 1 + ptr->number_of_philosophers) % ptr->number_of_philosophers;
		// printf("this is the right fork: %d\n", philos[i].right_fork);
		// printf("this is the left fork: %d\n", philos[i].left_fork);
		philos[i].thread_ret = pthread_create(&philos[i].thread_id, NULL, philo_routine, (void *) &philos[i]);
		usleep(1000);
		i++;
	}
}

int main(int ac, char **av)
{
	t_parameters	*param;

	param = malloc(sizeof(t_parameters));
	if (ac == 5 || ac == 6)
	{
		if (!check_parameter(ac, av, param))
			return (0);
		initialize_parameters(ac, av, param);
		create_philos_threads(param);
		// printf("%d\n%d\n%d\n%d\n%d\n", param->number_of_philosophers, param->time_to_die, param->time_to_eat, param->time_to_sleep, param->must_eat);
	}
	return (0);
}
