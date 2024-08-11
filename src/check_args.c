/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:23:36 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/08/07 14:26:36 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_all_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else
				return (false);
		}
		j = 0;
		i++;
	}
	return (true);
}

void	assign_input(t_philodata *philodata, int argc, char **argv)
{
	philodata->nbr_of_philos = atoi(argv[1]);
	philodata->time_to_die = atoi(argv[2]);
	philodata->time_to_eat = atoi(argv[3]);
	philodata->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		philodata->max_eat_occurences = atoi(argv[5]);
	else
		philodata->max_eat_occurences = -1;
}

bool	is_correct_input(int argc, char **argv)
{
	if ((argc == 5 || argc == 6) && (is_all_number(argv) == true))
	{
		printf("args are all g\n");
		return (true);
	}	
	else
	{
		printf("args are NOT OKAYYY\n");
		return (false);
	}
}