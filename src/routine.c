/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:04:17 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/08/17 10:04:19 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*the_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	ft_usleep(5);
	//if (philo->simdata->philo_dead == 0 && philo->simdata->all_full = 0)
		//then you may print whatever message
	print_message(philo, "is a philosopher.\n");

	// print_message (they died)
	return NULL;
}

void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->simdata->message_lock);
	printf("%lu%4d %s", get_timestamp(philo->simdata), philo->id, message);
	pthread_mutex_unlock(&philo->simdata->message_lock);
	return ;
}

// void	sim_stop(t_simdata *simdata)
// {
// 	int	i;
// 	while (1)
// 	{
// 		i = 0;
// 		while(i < simdata->nbr_philos)
// 		{
// 			if (simdata->philos[i]->meals_eaten >= simdata->til_full)
// 			i++;
// 		}
// 		(simdata-> != 0)

// 	}


// }