/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:41:14 by dpaal             #+#    #+#             */
/*   Updated: 2022/10/03 21:20:38 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		ret;
	t_env	*env;

	if (argc != 5 && argc != 6)
		return (error_message("Wrong amount of Arguments!\n Usage:\
		./philo <number of philosophers> <time to die> <time to eat>\
		<time to sleep> [times must eat]"));
	env = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!env)
		error_message("Allocation failed!");
	ret = initialize(env, argv);
	if (ret)
		return (error_manager(ret));
	if (launch(env))
		return (error_message("There was an error creating the threads"));
	free(env);
	return (0);
}
