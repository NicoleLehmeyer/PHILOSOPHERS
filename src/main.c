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
	t_philodata	philodata;

	if (!is_correct_input(argc, argv))
	{
		printf("Not going to assign tf bitch\n");
		return (0);
	}
	assign_input(&philodata, argv);
	printf("Number of philos: %d\n", philodata.nbr_of_philos);
	printf("Number of philos: %d\n", philodata.time_to_die);
	printf("Number of philos: %d\n", philodata.time_to_eat);
	printf("Number of philos: %d\n", philodata.time_to_sleep);
	printf("Number of philos: %d\n", philodata.max_eat_occurences);
	return (0);
}