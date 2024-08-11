/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:53:09 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/08/07 12:53:13 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "LIBFT/include/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_simdata
{
	int		nbr_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		max_eat_occurences;
	t_philo	**philos;
}				t_simdata;

typedef struct	s_philo
{
	int			id;
	int			meals_eaten;
	int			time_since_last_meal;
	pthread_t	thread;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	l_fork;
	
}				t_philo;

// **main.c** //
int	main(int argc, char **argv);

// **check_args.c** //	
bool	is_correct_input(int argc, char **argv);
void	assign_input(t_simdata *simdata, int argc, char **argv);
bool	is_all_number(char **argv);

// *initialise.c* //
void	init_philos(t_simdata *simdata);


#endif