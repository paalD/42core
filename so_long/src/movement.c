/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:49:22 by dpaal             #+#    #+#             */
/*   Updated: 2022/09/26 16:49:49 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_vars *vars)
{
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = '0';
	vars->img.pos.y -= 1;
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = 'P';
	vars->game.count_steps++;
	return (0);
}

int	move_down(t_vars *vars)
{
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = '0';
	vars->img.pos.y += 1;
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = 'P';
	vars->game.count_steps++;
	return (0);
}

int	move_left(t_vars *vars)
{
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = '0';
	vars->img.pos.x -= 1;
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = 'P';
	vars->game.count_steps++;
	return (0);
}

int	move_right(t_vars *vars)
{
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = '0';
	vars->img.pos.x += 1;
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = 'P';
	vars->game.count_steps++;
	return (0);
}
