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
	t_simdata *simdata;

	simdata = (t_simdata *)arg;
	printf("I'm Doing the routine TOTAL PHILOS %d\n", simdata->nbr_philos);
	return NULL;
}

void	print_message(t_philo philo, char *message)
{
	pthread_mutex_lock(&philo->simdata.message_lock);
	printf("&lu\t%d %s")
	pthread_mutex_unlock(&philo->simdata.message_lock);
	return ;
}