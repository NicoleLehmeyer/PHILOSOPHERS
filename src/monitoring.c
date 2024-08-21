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
	if (pthread_create(&simdata->dead_checker, NULL, death_check, simdata) != 0)
		ft_error("Filed to create dead_checker thread.\n", simdata);
	if (pthread_create(&simdata->full_checker, NULL, full_check, simdata) != 0)
		ft_error("Filed to create full_checker thread.\n", simdata);
	if (pthread_mutex_init(&simdata->endsim_lock, NULL) != 0)
		ft_error("Unable to initialise fork mutex.", simdata);
	while (1)
	{
		pthread_mutex_lock(&simdata->endsim_lock);
		if (simdata->philo_dead != 0 || simdata->all_full != 0)
		{
			pthread_mutex_unlock(&simdata->endsim_lock);
			return ;
		}
		pthread_mutex_unlock(&simdata->endsim_lock);
	}
	return ;
}

/*
void	end_sim(t_simdata *simdata)
{
	if (pthread_create(&simdata->dead_checker, NULL, death_check,
			&simdata) != 0)
		ft_error("Filed to create dead_checker thread.\n", simdata);
	if (pthread_create(&simdata->full_checker, NULL, full_check, &simdata) != 0)
		ft_error("Filed to create full_checker thread.\n", simdata);
	while (1)
	{
		if (simdata->philo_dead != 0 || simdata->all_full != 0)
			return ;
	}
	return ;
}
*/

void	*full_check(void *arg)
{
	t_simdata	*simdata;
	int			i;

	simdata = (t_simdata *)arg;
	while (simdata->all_full == 0 && simdata->philo_dead == 0)
	{
		i = 0;
		while (i < simdata->nbr_philos)
		{
			if (simdata->philos[i].meals_eaten < simdata->til_full)
				break ;
			i++;
		}
		if (i > simdata->nbr_philos)
		{
			simdata->all_full = 1;
			return (NULL);
		}
		ft_usleep(50);
	}
	return (NULL);
}

void	*death_check(void *arg)
{
	t_simdata	*simdata;
	int			i;

	simdata = (t_simdata *)arg;
	while (simdata->all_full == 0 && simdata->philo_dead == 0)
	{
		i = 0;
		while (i < simdata->nbr_philos)
		{
			if (get_curr_time() - simdata->philos[i].time_last_eat >= simdata->time_die)
			{
				print_message(&simdata->philos[i], "died");
				simdata->philo_dead = 1;
			}
			else
				i++;
		}
		ft_usleep(50);
	}
	return (NULL);
}
