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
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_simdata	t_simdata;

typedef struct s_forks
{
	int				f_id;
	pthread_mutex_t	f_lock;
}				t_forks;

typedef struct 		s_philo
{
	int				id;
	int				meals_eaten;
	long			time_last_eat;
	pthread_t		p_tid;
	pthread_mutex_t	*f_left;
	pthread_mutex_t	*f_right;
	t_simdata		*simdata;
}					t_philo;

typedef struct s_simdata
{
	int				nbr_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				til_full;
	long			start_time;
	t_philo			*philos;
	t_forks			*fork;
	int				philo_dead;
	int				all_full;
	pthread_t		full_checker;
	pthread_t		dead_checker;
	pthread_mutex_t	endsim_lock;
	pthread_mutex_t	message_lock;
}				t_simdata;

// ** main.c ** //
void	ft_error(char *err_msg, t_simdata *simdata);
void	free_exit(t_simdata *simdata);
void	free_exit2(t_simdata *simdata);
int		main(int argc, char **argv);

// ** check_args.c ** //	
bool	is_correct_input(int argc, char **argv);
void	assign_input(t_simdata *simdata, int argc, char **argv);
bool	is_all_number(char **argv);

// ** initialise.c ** //
void	init_philos(t_simdata *simdata);
void	init_forks(t_simdata *simdata);

// ** time.c ** //
long	get_curr_time(void);
long	get_timestamp(t_simdata *simdata);
int		ft_usleep(long millisec);

// ** routine.c ** //
void	*the_routine(void *arg);
void	solo_eat(t_philo *philo);
void	eat(t_philo *philo);
void	print_message(t_philo *philo, char *message);

// ** monitoring.c ** //
void	end_sim(t_simdata *simdata);
void	*full_check(void *arg);
void	*death_check(void *arg);

#endif