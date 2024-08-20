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

void	ft_error(char *err_msg, t_simdata *simdata)
{
	printf("%s\n", err_msg);
	free_exit(simdata);
	exit (1);
}

void	free_exit(t_simdata *simdata)
{
	int	i;
	if (simdata->philos)
	{
		i = 0;
		while (i < simdata->nbr_philos)
		{
			pthread_join(simdata->philos[i].p_tid, NULL);
			i++;
		}
		free(simdata->philos);
	}
	if (simdata->fork)
	{
		i = 0;
		while (i < simdata->nbr_philos)
		{
			pthread_mutex_destroy(&simdata->fork[i].f_lock);
			i++;
		}
		free(simdata->fork);
	}
	free_exit2(simdata);
	free(simdata);
	return ;
}

void	free_exit2(t_simdata *simdata)
{
	pthread_mutex_destroy(&simdata->message_lock);
	pthread_join(simdata->full_checker, NULL);
	pthread_join(simdata->dead_checker, NULL);
}

int	main(int argc, char **argv)
{
	t_simdata	*simdata;

	simdata = malloc(sizeof(t_simdata));
	assign_input(simdata, argc, argv);
	init_philos(simdata);
	init_forks(simdata);
	end_sim(simdata);
	free_exit(simdata);
	return (0);
}