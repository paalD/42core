/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:56:13 by dpaal             #+#    #+#             */
/*   Updated: 2022/10/06 11:06:28 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_incr(int *i, t_env *env)
{
	mtx_get(&(env->check));
	*i += 1;
	mtx_rel(&(env->check));
}

void	*p_thread(void *void_philo)
{
	t_philo	*philo;
	t_env	*env;

	philo = (t_philo *)void_philo;
	env = philo->env;
	while (mtx_check(&(env->alive)))
	{
		action_print(env, philo->id, "is thinking");
		while (try_eat(philo) && mtx_check(&(env->alive)))
		{
			if (env->time_death - time_diff(philo->t_last_meal, timestamp()) <= \
				env->time_eat + 100)
			{
				force_eat(philo);
				break ;
			}
			usleep(50);
		}
		if (!mtx_check(&(env->hungry)))
			break ;
		action_print(env, philo->id, "is sleeping");
		smart_sleep(env->time_sleep, env);
	}
	return (NULL);
}

void	exit_launcher(t_env *env, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < env->nb_philo && env->nb_philo > 1)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < env->nb_philo)
	{
		pthread_mutex_destroy(&(env->forks[i].mtx));
		i++;
	}
	pthread_mutex_destroy(&(env->writing.mtx));
	pthread_mutex_destroy(&(env->alive.mtx));
	pthread_mutex_destroy(&(env->meal_check.mtx));
	pthread_mutex_destroy(&(env->hungry.mtx));
}

void	death_checker(t_env *env, t_philo *p)
{
	int	i;

	while (mtx_check(&(env->hungry)))
	{
		i = -1;
		while (++i < env->nb_philo && mtx_check(&(env->alive)))
		{
			mtx_get(&(env->meal_check));
			if (time_diff(p[i].t_last_meal, timestamp()) > env->time_death)
			{
				action_print(env, i, "died");
				mtx_get(&(env->alive));
			}
			mtx_rel(&(env->meal_check));
			usleep(50);
		}
		if (!mtx_check(&(env->alive)))
			break ;
		i = 0;
		while (env->nb_eat != -1 && i < env->nb_philo && \
			p[i].x_ate >= env->nb_eat)
			check_incr(&i, env);
		if (i == env->nb_philo)
			mtx_get(&(env->hungry));
	}
}

int	launch(t_env *env)
{
	int		i;
	t_philo	*phi;

	i = 0;
	phi = env->philo;
	env->first_timestamp = timestamp();
	while (i < env->nb_philo)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, p_thread, &(phi[i])))
			return (1);
		phi[i].t_last_meal = timestamp();
		i++;
	}
	death_checker(env, env->philo);
	exit_launcher(env, phi);
	return (0);
}
