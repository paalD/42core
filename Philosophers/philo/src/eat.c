/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:53:23 by dpaal             #+#    #+#             */
/*   Updated: 2022/10/06 11:05:55 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	force_eat(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	mtx_get(&(env->forks[philo->l_fork_id]));
	action_print(env, philo->id, "has taken a fork");
	mtx_get(&(env->forks[philo->r_fork_id]));
	action_print(env, philo->id, "has taken a fork");
	mtx_get(&(env->meal_check));
	action_print(env, philo->id, "is eating");
	philo->t_last_meal = timestamp();
	mtx_rel(&(env->meal_check));
	smart_sleep(env->time_eat, env);
	mtx_get(&(env->check));
	(philo->x_ate)++;
	mtx_rel(&(env->check));
	mtx_rel(&(env->forks[philo->l_fork_id]));
	mtx_rel(&(env->forks[philo->r_fork_id]));
}

int	try_eat(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	if (!(mtx_check(&(env->forks[philo->l_fork_id]))) || \
		!(mtx_check(&(env->forks[philo->r_fork_id]))))
		return (1);
	mtx_get(&(env->forks[philo->l_fork_id]));
	mtx_get(&(env->forks[philo->r_fork_id]));
	action_print(env, philo->id, "has taken a fork");
	action_print(env, philo->id, "has taken a fork");
	mtx_get(&(env->meal_check));
	action_print(env, philo->id, "is eating");
	philo->t_last_meal = timestamp();
	mtx_rel(&(env->meal_check));
	smart_sleep(env->time_eat, env);
	mtx_get(&(env->check));
	(philo->x_ate)++;
	mtx_rel(&(env->check));
	mtx_rel(&(env->forks[philo->l_fork_id]));
	mtx_rel(&(env->forks[philo->r_fork_id]));
	return (0);
}
