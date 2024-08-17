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
	printf("I'm Doing the routine TOTAL PHILOS %d\n", simdata->nbr_of_philos);
	return NULL;
}