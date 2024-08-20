/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:31:57 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/08/12 10:31:59 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	end_sim(t_simdata *simdata)
{
	int	i;
	while (simdata->all_full == 0 || simdata->philo_dead == 0)
	{
		i = 0;
		while (i < simdata->nbr_philos && simdata->philo_dead == 0)
		{
			pthrea
		}
	}
	return ;
}

void	death_check(t_philo *philo)
{

	return ;
}

//check cases which end simulation
//these will be 2 extra threads! maybe
//1. check & compare all philos number of meals to argv[6]
//2. check & compare time_to_die to the time since last meal/start of sim

//simdata->philos[i] = pthread_create(&philos[i].thread, ) // how does this function workkkkk?
	//error handling if we can't create the thread