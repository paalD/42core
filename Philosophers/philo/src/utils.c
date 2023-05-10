/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:23:54 by dpaal             #+#    #+#             */
/*   Updated: 2022/10/06 11:06:44 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	smart_sleep(long long time, t_env *env)
{
	long long	i;

	i = timestamp();
	while (mtx_check(&(env->alive)))
	{
		if (time_diff(i, timestamp()) >= time)
			break ;
		usleep(50);
	}
}

void	action_print(t_env *env, int id, char *string)
{
	while (!mtx_check(&(env->writing)))
		usleep(50);
	mtx_get(&(env->writing));
	if (mtx_check(&(env->alive)))
	{
		printf("%-5lli %3i %s\n", timestamp() - \
			env->first_timestamp, id + 1, string);
	}
	mtx_rel(&(env->writing));
	return ;
}
