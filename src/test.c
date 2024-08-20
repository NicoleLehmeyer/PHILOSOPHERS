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


void	death(t_data *data)
{
	int	i;

	while (data->finished != 1 || data->dead != 1)
	{
		i = 0;
		while (i < data->n_philo && data->dead != 1)
		{
			is_dead(data, i);
			i++;
		}
		if (data->dead == 1)
			break ;
		i = 0;
		while (data->n_meals != -1 && data->philos[i].count >= data->n_meals
			&& i < data->n_philo)
			i++;
		if (i == data->n_philo)
			data->finished = 1;
	}
}

void	is_dead(t_data *data, int i)
{
	pthread_mutex_lock(&data->lock);
	if (get_time() - data->philos[i].last_meal > (size_t)data->t_death)
	{
		message(&data->philos[i], "died");
		data->dead = 1;
	}
	pthread_mutex_unlock(&data->lock);
	usleep(100);
}

// #include "../include/philo.h"

// #include <stdio.h>
// # include <pthread.h>
// # include <sys/time.h>

// void	*increment(void *p)
// {
// 	int *i = (int *)p;

// 	i[0]++;
// 	return i;
// }

// int main ()
// {
// 	pthread_t *thread;
// 	int p = 0;

// 	pthread_create(thread, NULL, increment, &p);
// 	pthread_create(&thread[1], NULL, increment, &p);

// 	pthread_join(thread[0], NULL);
// 	pthread_join(thread[1], NULL);
// 	printf("p == %d\n", p);
// 	return (0);
// }

//PRINT PHILO'S LEFT AND RIGHT FORK ID. USE AFTER FORKS ALLOCATED IN init_fork()
	// int i = 0;
	// while (i < simdata->nbr_philos)
	// {
	// 	printf("Philo[%d] Left Fork[%d]: %d\n", i, i, simdata->philos[i].f_left.f_id);
	// 	printf("Philo[%d] Right Fork[%d]: %d\n", i, i, simdata->philos[i].f_right.f_id);
	// 	i++;
	// }

//TEST TIME AND PRINT SIMDATA DATA
	// int i = 0;
	// while (i < simdata.nbr_philos)
	// {
	// 	usleep(1000);
	// 	simdata.philos[i].time_since_last_meal = get_timestamp(&simdata);
	// 	printf("Philo[%d] id/mealseaten/timesince: %d, %d, %lu\n", i, simdata.philos[i].id, simdata.philos[i].meals_eaten, simdata.philos[i].time_since_last_meal);
	// 	i++;
	// }
	// printf("Number of philos: %d\n", simdata.nbr_philos);
	// printf("Time to die: %d\n", simdata.time_to_die);
	// printf("Time to eat: %d\n", simdata.time_to_eat);
	// printf("Time to sleep: %d\n", simdata.time_to_sleep);
	// printf("Max eat occurences: %d\n", simdata.max_eat_occurences);
