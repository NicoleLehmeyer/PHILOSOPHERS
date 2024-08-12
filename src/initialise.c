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
	simdata->philos=malloc((sizeof(t_philo) * simdata->nbr_of_philos));
	if (!simdata->philos)
		return ;
	while (i < simdata->nbr_of_philos)
	{
		simdata->philos[i].id = i;
		simdata->philos[i].meals_eaten = 0;
		simdata->philos[i].time_since_last_meal = 0; //need to sus how to handle time stuff in this project
		//simdata->philos[i].r_fork //initialise mutex?
		//simdata->philos[i].l_fork //initialise mutex?
		i++;
	}
}

// init the forks
// the right fork of the last philo should have the same mutex id as the first philosopher's left fork.