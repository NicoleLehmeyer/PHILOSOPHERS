// #include "../include/philo.h"

// #include <stdio.h>
// # include <pthread.h>
// # include <sys/time.h>

// void	*increment(void *p)
// {
// 	int *i = (int *)p;

// 	i[0]++;
// 	return i;
// }

// int main ()
// {
// 	pthread_t *thread;
// 	int p = 0;

// 	pthread_create(thread, NULL, increment, &p);
// 	pthread_create(&thread[1], NULL, increment, &p);

// 	pthread_join(thread[0], NULL);
// 	pthread_join(thread[1], NULL);
// 	printf("p == %d\n", p);
// 	return (0);
// }