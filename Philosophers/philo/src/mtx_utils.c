/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:25:51 by dpaal             #+#    #+#             */
/*   Updated: 2022/10/04 18:15:37 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mtx_init(t_mutex *mutex)
{
	if (pthread_mutex_init(&mutex->mtx, NULL))
		return (1);
	mutex->rdy = 1;
	return (0);
}

int	mtx_get(t_mutex *mutex)
{
	int	res;

	while (!mtx_check(mutex))
		usleep(1);
	pthread_mutex_lock(&mutex->mtx);
	res = mutex->rdy;
	mutex->rdy = 0;
	pthread_mutex_unlock(&mutex->mtx);
	return (res);
}

int	mtx_check(t_mutex *mutex)
{
	int	res;

	pthread_mutex_lock(&mutex->mtx);
	res = mutex->rdy;
	pthread_mutex_unlock(&mutex->mtx);
	return (res);
}

void	mtx_rel(t_mutex *mutex)
{
	pthread_mutex_lock(&mutex->mtx);
	mutex->rdy = 1;
	pthread_mutex_unlock(&mutex->mtx);
}
