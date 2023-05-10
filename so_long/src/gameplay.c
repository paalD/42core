/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:28:08 by dpaal             #+#    #+#             */
/*   Updated: 2022/09/27 15:20:45 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_map(t_vars *vars)
{
	int	rows;

	rows = 0;
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	while (rows < vars->map.size.y)
	{
		free(vars->map.mtx[rows]);
		rows++;
	}
	free(vars->map.mtx);
	return (0);
}

int	complete_game(t_vars *vars, char *congrats)
{
	ft_printf(congrats);
	close_map(vars);
	exit(0);
}

int	check_points(t_vars *vars)
{
	if (count_points(vars) == 0)
		complete_game(vars, "You've won the game!\n");
	else
		ft_printf("Eat all brains!\n");
	return (0);
}

int	move(int keycode, t_vars *vars)
{
	if ((keycode == D_KEY)
		&& (vars->map.mtx[vars->img.pos.y][vars->img.pos.x + 1] == 'E'))
		check_points(vars);
	else if ((keycode == D_KEY)
		&& (vars->map.mtx[vars->img.pos.y][vars->img.pos.x + 1] != '1'))
		move_right(vars);
	if ((keycode == A_KEY)
		&& (vars->map.mtx[vars->img.pos.y][vars->img.pos.x - 1] == 'E'))
		check_points(vars);
	else if ((keycode == A_KEY)
		&& (vars->map.mtx[vars->img.pos.y][vars->img.pos.x - 1] != '1'))
		move_left(vars);
	if ((keycode == S_KEY)
		&& (vars->map.mtx[vars->img.pos.y + 1][vars->img.pos.x] == 'E'))
		check_points(vars);
	else if ((keycode == S_KEY)
		&& (vars->map.mtx[vars->img.pos.y + 1][vars->img.pos.x] != '1'))
		move_down(vars);
	if ((keycode == W_KEY)
		&& (vars->map.mtx[vars->img.pos.y - 1][vars->img.pos.x] == 'E'))
		check_points(vars);
	else if ((keycode == W_KEY)
		&& (vars->map.mtx[vars->img.pos.y - 1][vars->img.pos.x] != '1'))
		move_up(vars);
	return (0);
}

int	use_key(int keycode, t_vars *vars)
{
	int		steps;

	steps = vars->game.count_steps;
	if (keycode == ESC)
		complete_game(vars, "The game was closed with ESC.\n");
	else
		move(keycode, vars);
	if (steps != vars->game.count_steps)
		ft_printf("Steps: %d\n", steps);
	draw_map(*vars);
	return (0);
}
