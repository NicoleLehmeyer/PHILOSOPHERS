/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:29:41 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/08/07 14:29:44 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *err_msg)
{
	printf("%s\n", err_msg);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_simdata	simdata;

	if (!is_correct_input(argc, argv))
	{
		printf("Not going to assign tf bitch\n");
		return (0);
	}
	assign_input(&simdata, argc, argv);
	init_philos(&simdata);
	simdata.start_time = get_curr_time();
	printf("Current time in milliseconds: %lu\n", simdata.start_time);
	init_philos(&simdata);
	init_forks(&simdata);

	int i = 0
	while (simdata->forks[i])
	{
		printf("Fork[%d]: %d", i)
	}
	i = 0;
	while (simdata->philo[i])
	{
		
		printf("Philo[%d]: Left Fork:", i, )
	}

	// int i = 0;
	// while (i < simdata.nbr_of_philos)
	// {
	// 	usleep(1000);
	// 	simdata.philos[i].time_since_last_meal = get_timestamp(&simdata);
	// 	printf("Philo[%d] id/mealseaten/timesince: %d, %d, %lu\n", i, simdata.philos[i].id, simdata.philos[i].meals_eaten, simdata.philos[i].time_since_last_meal);
	// 	i++;
	// }
	// printf("Number of philos: %d\n", simdata.nbr_of_philos);
	// printf("Time to die: %d\n", simdata.time_to_die);
	// printf("Time to eat: %d\n", simdata.time_to_eat);
	// printf("Time to sleep: %d\n", simdata.time_to_sleep);
	// printf("Max eat occurences: %d\n", simdata.max_eat_occurences);
	return (0);
}