/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:59:29 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/08/20 12:59:31 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "../include/philo.h"

#include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

void	*increment(void *p)
{
	int *i = (int *)p;

	i[0]++;
	return i;
}

int main ()
{
	pthread_t *thread;
	int p = 0;

	pthread_create(thread, NULL, increment, &p);
	pthread_create(&thread[1], NULL, increment, &p);

	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	printf("p == %d\n", p);
	return (0);
}
*/

/*
PRINT PHILO'S LEFT AND RIGHT FORK ID. USE AFTER FORKS ALLOCATED IN init_fork()
	int i = 0;
	while (i < simdata->nbr_philos)
	{
		printf("Philo[%d] Left Fork[%d]: %d\n", i, i, 
			simdata->philos[i].f_left.f_id);
		printf("Philo[%d] Right Fork[%d]: %d\n", i, i,
			simdata->philos[i].f_right.f_id);
		i++;
	}
*/

/*
TEST TIME AND PRINT SIMDATA DATA
	int i = 0;
	while (i < simdata.nbr_philos)
	{
		usleep(1000);
		simdata.philos[i].time_since_last_meal = get_timestamp(&simdata);
		printf("Philo[%d] id/mealseaten/timesince: %d, %d, %lu\n", i,
			simdata.philos[i].id, simdata.philos[i].meals_eaten,
			simdata.philos[i].time_since_last_meal);
		i++;
	}
	printf("Number of philos: %d\n", simdata.nbr_philos);
	printf("Time to die: %d\n", simdata.time_to_die);
	printf("Time to eat: %d\n", simdata.time_to_eat);
	printf("Time to sleep: %d\n", simdata.time_to_sleep);
	printf("Max eat occurences: %d\n", simdata.max_eat_occurences);
*/

/*
int main()
{
	struct timeval time;

	gettimeofday(&time, NULL);
	printf("tv_sec == %ld	tv_usec == %d\n", time.tv_sec * 1000,
		time.tv_usec / 1000);
	return (0);
}
*/

/*
void	init_forks(t_simdata *simdata)
{
	int	i;

	i = 0;
	simdata->fork = malloc(sizeof(t_forks) * simdata->nbr_philos);
	if (!simdata->fork)
		ft_error("Unable to malloc forks array.", simdata);
	while (i < simdata->nbr_philos)
	{
		if (pthread_mutex_init(&simdata->fork[i].f_lock, NULL) != 0)
			ft_error("Unable to initialise fork mutex.", simdata);
		else
			simdata->fork[i].f_id = i;
		i++;
	}
	i = 0;
	while (i < simdata->nbr_philos)
	{
		simdata->philos[i].f_left = &simdata->fork[i].f_lock;
		if (i == 0)
			simdata->philos[i].f_right = &simdata->fork[simdata->nbr_philos - 1]
				.f_lock;
		else
			simdata->philos[i].f_right = &simdata->fork[i - 1].f_lock;
		if (pthread_create(&simdata->philos[i].p_tid, NULL, the_routine,
				&simdata->philos[i]) != 0)
			ft_error("Failed to create philo thread.\n", simdata);
		i++;
	}
}*/