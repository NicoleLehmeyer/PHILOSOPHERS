/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:58:54 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/08/07 16:58:56 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_simdata *simdata)
{
	int	i;

	i = 0;
	simdata->philos = malloc((sizeof(t_philo) * simdata->nbr_of_philos));
	if (!simdata->philos)
		return ;
	while (i < simdata->nbr_of_philos)
	{
		simdata->philos[i].id = i;
		simdata->philos[i].meals_eaten = 0;
		simdata->philos[i].time_since_last_meal = 0;
		if (pthread_create(&simdata->philos[i].p_tid, NULL, the_routine, simdata) != 0)
			ft_error("Failed to create thread.");
		printf("Philo[%d] initiated", i);
		if (pthread_join(simdata->philos[i].p_tid, NULL) != 0)
			ft_error("Failed to join thread.");
		printf("Threads have finished execution.\n");
		i++;
	}
}

void	init_forks(t_simdata *simdata)
{
	int	i;

	i = 0;
	simdata->fork = malloc(sizeof(pthread_mutex_t) * simdata->nbr_of_philos);
	if (!simdata->fork)
		ft_error("Unable to malloc forks array.");
	while (i < simdata->nbr_of_philos)
	{
		if (pthread_mutex_init(&simdata->fork[i].f_lock, NULL) != 0)
			ft_error("Unable to initialise fork mutex.");
		else
		{
			pthread_mutex_init(&simdata->fork[i].f_lock, NULL);
			simdata->fork[i].f_id = i;
		}
		i++;
	}
	i = 0;
	while (i < simdata->nbr_of_philos)
	{
		simdata->philos[i].f_left = simdata->fork[i];
		if (i == 0)
			simdata->philos[i].f_right = simdata->fork[simdata->nbr_of_philos - 1];
		else
			simdata->philos[i].f_right = simdata->fork[i - 1];
		i++;
	}
}
