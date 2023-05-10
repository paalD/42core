/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:19:16 by dpaal             #+#    #+#             */
/*   Updated: 2022/09/27 15:03:03 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_vars	vars;

	check_arg(argc, argv);
	get_map_size(&vars, argv);
	initialize_map(&vars, argv);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.size.x * SPR_WIDTH,
			vars.map.size.y * SPR_HEIGHT, "so_long");
	place_player(&vars);
	count_points(&vars);
	draw_map(vars);
	mlx_hook(vars.win, 2, 1L << 0, use_key, &vars);
	mlx_hook(vars.win, 17, 1l << 0, mlx_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
