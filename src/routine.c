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
	print_message(philo, "is a philosopher.\n");
	return NULL;
}

void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->simdata->message_lock);
	printf("%lu%4d %s", get_timestamp(philo->simdata), philo->id, message);
	pthread_mutex_unlock(&philo->simdata->message_lock);
	return ;
}