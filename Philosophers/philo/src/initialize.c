/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:56:15 by dpaal             #+#    #+#             */
/*   Updated: 2022/10/04 18:20:48 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		if (mtx_init(&(env->forks[i])))
			return (1);
		i++;
	}
	if (mtx_init(&(env->alive)))
		return (1);
	if (mtx_init(&(env->hungry)))
		return (1);
	if (mtx_init(&(env->writing)))
		return (1);
	if (mtx_init(&(env->meal_check)))
		return (1);
	if (mtx_init(&(env->check)))
		return (1);
	return (0);
}

int	init_philosophers(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		env->philo[i].id = i;
		env->philo[i].x_ate = 0;
		env->philo[i].l_fork_id = i;
		env->philo[i].t_last_meal = 0;
		env->philo[i].env = env;
		env->philo[i].r_fork_id = (i + 1) % env->nb_philo;
		i++;
	}
	return (0);
}

int	initialize(t_env *env, char **argv)
{
	env->nb_philo = ft_atoi(argv[1]);
	env->time_death = ft_atoi(argv[2]);
	env->time_eat = ft_atoi(argv[3]);
	env->time_sleep = ft_atoi(argv[4]);
	env->alive.rdy = 1;
	if (env->nb_philo < 1 || env->time_death < 0 || env->time_eat < 0
		|| env->time_sleep < 0 || env->nb_philo > 200)
		return (1);
	if (argv[5])
	{
		env->nb_eat = ft_atoi(argv[5]);
		if (env->nb_eat <= 0)
			return (1);
	}
	else
		env->nb_eat = -1;
	if (init_mutex(env))
		return (2);
	init_philosophers(env);
	return (0);
}
