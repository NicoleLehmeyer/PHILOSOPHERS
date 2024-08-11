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
	printf("Number of philos: %d\n", simdata.nbr_of_philos);
	printf("Number of philos: %d\n", simdata.time_to_die);
	printf("Number of philos: %d\n", simdata.time_to_eat);
	printf("Number of philos: %d\n", simdata.time_to_sleep);
	printf("Number of philos: %d\n", simdata.max_eat_occurences);
	return (0);
}