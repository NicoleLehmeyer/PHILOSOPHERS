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

void    init_philos(t_simdata *simdata)
{
	int i;
	
	i = 0;
	simdata->philos = malloc((sizeof(t_philo) * simdata->nbr_of_philos));
	if (!simdata->philos)
		return ;
	while (i < simdata->nbr_of_philos)
	{
		simdata->philos[i].id = i;
		simdata->philos[i].meals_eaten = 0;
		simdata->philos[i].time_since_last_meal = 0;
		i++;
	}
}

void	init_forks(t_simdata *simdata)
{
	int	i;

	i = 0;
	simdata->forks = malloc(sizeof(pthread_mutex_t) * simdata->nbr_of_philos);
	if (!simdata->forks)
		ft_error("Unable to malloc forks array.");
	while (i < simdata->nbr_of_philos)
 	{
		if (pthread_mutex_init(&simdata->forks[i], NULL) != 0)
			ft_error("Unable to initialise fork mutex");
		i++;
	}
	i = 0;
	while (i < simdata->nbr_of_philos)
	{
		simdata->philos[i].l_fork = simdata->forks[i];
		if (i == 0)
			simdata->philos[i].r_fork = simdata->forks[simdata->nbr_of_philos - 1];
		else
			simdata->philos[i].r_fork = simdata->forks[i - 1];
		i++;
	}
}
