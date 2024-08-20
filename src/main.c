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

// void	free_exit(t_simdata *simdata)
// {

// 	//join the threads
// 	//destroy the fork mutexes
// 	//destroy the simstop mutex
// 	//destroy the printing mutex
// 	//free fork array
// 	//free philos array
// 	//free simdata
// }

int	main(int argc, char **argv)
{
	t_simdata	*simdata;

	simdata = malloc(sizeof(t_simdata));
	if (!is_correct_input(argc, argv))
	{
		printf("Not going to assign tf bitch\n");
		return (0);
	}
	assign_input(simdata, argc, argv);
	simdata->start_time = get_curr_time();
	init_philos(simdata);
	init_forks(simdata);
	printf("Current time in milliseconds: %lu\n", simdata->start_time);
	// int i = 0;
	// while (i < simdata->nbr_philos)
	// {
	// 	printf("Philo[%d] Left Fork[%d]: %d\n", i, i, simdata->philos[i].f_left.f_id);
	// 	printf("Philo[%d] Right Fork[%d]: %d\n", i, i, simdata->philos[i].f_right.f_id);
	// 	i++;
	// }
	

	// 	printf("Philo[%d]: Left Fork:", i, )
	// }

	// int i = 0;
	// while (i < simdata.nbr_philos)
	// {
	// 	usleep(1000);
	// 	simdata.philos[i].time_since_last_meal = get_timestamp(&simdata);
	// 	printf("Philo[%d] id/mealseaten/timesince: %d, %d, %lu\n", i, simdata.philos[i].id, simdata.philos[i].meals_eaten, simdata.philos[i].time_since_last_meal);
	// 	i++;
	// }
	// printf("Number of philos: %d\n", simdata.nbr_philos);
	// printf("Time to die: %d\n", simdata.time_to_die);
	// printf("Time to eat: %d\n", simdata.time_to_eat);
	// printf("Time to sleep: %d\n", simdata.time_to_sleep);
	// printf("Max eat occurences: %d\n", simdata.max_eat_occurences);
	return (0);
}