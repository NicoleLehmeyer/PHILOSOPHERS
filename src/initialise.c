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
	simdata->philos = malloc((sizeof(t_philo) * simdata->nbr_philos));
	if (!simdata->philos)
		ft_error("Failed to malloc philos\n", simdata);
	while (i < simdata->nbr_philos)
	{
		simdata->philos[i].id = i + 1;
		simdata->philos[i].meals_eaten = 0;
		simdata->philos[i].time_last_eat = 0;
		simdata->philos[i].simdata = simdata;
		i++;
	}
}

void	init_forks(t_simdata *simdata)
{
	int	i;

	i = -1;
	simdata->fork = malloc(sizeof(t_forks) * simdata->nbr_philos);
	if (!simdata->fork)
		ft_error("Unable to malloc forks array.", simdata);
	while (++i < simdata->nbr_philos)
	{
		if (pthread_mutex_init(&simdata->fork[i].f_lock, NULL) != 0)
			ft_error("Unable to initialise fork mutex.", simdata);
		simdata->fork[i].f_id = i;
	}
	i = -1;
	while (++i < simdata->nbr_philos)
	{
		simdata->philos[i].f_left = &simdata->fork[i].f_lock;
		simdata->philos[i].f_right = &simdata->fork[simdata->nbr_philos - 1]
			.f_lock;
		if (i != 0)
			simdata->philos[i].f_right = &simdata->fork[i - 1].f_lock;
		if (pthread_create(&simdata->philos[i].p_tid, NULL, the_routine,
				&simdata->philos[i]) != 0)
			ft_error("Failed to create philo thread.\n", simdata);
	}
}
