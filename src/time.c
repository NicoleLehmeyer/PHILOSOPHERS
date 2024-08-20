/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:11:20 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/08/12 09:11:34 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_curr_time(void)
{
	struct timeval	current_time;
	long			millisec;

	gettimeofday(&current_time, NULL);
	millisec = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
	return (millisec);
}

long	get_timestamp(t_simdata *simdata)
{
	return (get_curr_time() - simdata->start_time);
}

int	ft_usleep(long millisec)
{
	long	start;

	start = get_curr_time();
	while ((get_curr_time() - start) < millisec)
		usleep(100);
	return (0);
}
