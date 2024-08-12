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

/*int main()
{
	struct timeval time;

	gettimeofday(&time, NULL);
	printf("tv_sec == %ld	tv_usec == %d\n", time.tv_sec * 1000, time.tv_usec / 1000);
	return (0);
}*/

// gettime()    --> to mark current time and find difference between that time and another

//comparison between (event time - start sim time in milliseconds) and arg value of time to eat/sleep/die
