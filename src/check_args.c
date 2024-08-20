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

void	assign_input(t_simdata *simdata, int argc, char **argv)
{
	if (!is_correct_input(argc, argv))
		ft_error("Incorrect input\n", simdata);
	simdata->nbr_philos = atoi(argv[1]);
	simdata->time_die = atoi(argv[2]);
	simdata->time_eat = atoi(argv[3]);
	simdata->time_sleep = atoi(argv[4]);
	simdata->til_full = -1;
	if (argc == 6)
		simdata->til_full = atoi(argv[5]);
	simdata->start_time = get_curr_time();
	simdata->philo_dead = 0;
	simdata->all_full = 0;
	if (pthread_mutex_init(&simdata->message_lock, NULL) != 0)
		ft_error("Unable to initialise message_lock mutex.\n", simdata);
}

bool	is_correct_input(int argc, char **argv)
{
	if ((argc == 5 || argc == 6) && (is_all_number(argv) == true))
		return (true);
	else
		return (false);
}