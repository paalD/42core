/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:41:18 by dpaal             #+#    #+#             */
/*   Updated: 2022/10/04 18:16:23 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int						id;
	int						x_ate;
	int						l_fork_id;
	int						r_fork_id;
	long long				t_last_meal;
	struct s_env			*env;
	pthread_t				thread_id;
}			t_philo;

typedef struct s_mutex
{
	int					rdy;
	pthread_mutex_t		mtx;
}			t_mutex;

typedef struct s_env
{
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	t_mutex				alive;
	t_mutex				hungry;
	long long			first_timestamp;
	t_mutex				meal_check;
	t_mutex				forks[200];
	t_mutex				writing;
	t_philo				philo[200];
	t_mutex				check;
}			t_env;

//			error.c
int			error_message(char *str);
int			error_manager(int error);

//			initialize.c
int			initialize(t_env *environment, char **argv);

//			launch.c
int			launch(t_env *environment);
void		exit_launcher(t_env *environment, t_philo *philos);

//			utils.c
void		action_print(t_env *environment, int id, char *string);
long long	timestamp(void);
long long	time_diff(long long past, long long pres);
void		smart_sleep(long long time, t_env *environment);

//			libft_utils.c
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_atoi(const char *str);

//			mtx_utils.c
int			mtx_init(t_mutex *mutex);
int			mtx_get(t_mutex *mutex);
int			mtx_check(t_mutex *mutex);
void		mtx_rel(t_mutex *mutex);

//			eat.c
int			try_eat(t_philo *philo);
void		force_eat(t_philo *philo);

#endif
