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

	if (philo->simdata->nbr_philos == 1)
	{
		solo_eat(philo);
		return NULL;
	}
	if (philo->id % 2 == 1)
		ft_usleep(50);
	while (philo->simdata->philo_dead == 0 && philo->simdata->all_full == 0)
	{
		eat(philo);
		if (philo->simdata->all_full == 0 && philo->simdata->philo_dead == 0)
			print_message(philo, "is sleeping");
		ft_usleep(philo->simdata->time_sleep);
		if (philo->simdata->all_full == 0 && philo->simdata->philo_dead == 0)
			print_message(philo, "is thinking");
	}
	return NULL;
}

void	solo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->f_left.f_lock);	
	print_message(philo, "grabbed a fork");
	ft_usleep(philo->simdata->time_die);
	print_message(philo, "died");
	pthread_mutex_unlock(&philo->f_left.f_lock);
	philo->simdata->philo_dead = 1;
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->f_left.f_lock);
	if (philo->simdata->all_full == 0 && philo->simdata->philo_dead == 0)
		print_message(philo, "grabbed a fork");
	pthread_mutex_lock(&philo->f_right.f_lock);
	if (philo->simdata->all_full == 0 && philo->simdata->philo_dead == 0)
	{
		print_message(philo, "grabbed a fork");
		print_message(philo, "is eating");
	}	
	philo->time_last_eat = get_curr_time();
	philo->meals_eaten++;
	ft_usleep(philo->simdata->time_eat);
	pthread_mutex_unlock(&philo->f_left.f_lock);
	pthread_mutex_unlock(&philo->f_right.f_lock);
	return ;
}

void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->simdata->message_lock);
	printf("%lu%4d %s\n", get_timestamp(philo->simdata), philo->id, message);
	pthread_mutex_unlock(&philo->simdata->message_lock);
	return ;
}
