/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:22:23 by dpaal             #+#    #+#             */
/*   Updated: 2022/09/26 19:38:03 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_graphics(t_vars vars, int rows, int columns)
{
	if (vars.map.mtx[rows][columns] == '1')
		vars.img.img_ptr = mlx_xpm_file_to_image(vars.mlx, "images/tree.xpm",
				&vars.img.size.x, &vars.img.size.y);
	else if (vars.map.mtx[rows][columns] == '0')
		vars.img.img_ptr = mlx_xpm_file_to_image(vars.mlx, "images/ground.xpm",
				&vars.img.size.x, &vars.img.size.y);
	else if (vars.map.mtx[rows][columns] == 'P')
		vars.img.img_ptr = mlx_xpm_file_to_image(vars.mlx, "images/zombie.xpm",
				&vars.img.size.x, &vars.img.size.y);
	else if (vars.map.mtx[rows][columns] == 'E')
		vars.img.img_ptr = mlx_xpm_file_to_image(vars.mlx, "images/grave.xpm",
				&vars.img.size.x, &vars.img.size.y);
	else if (vars.map.mtx[rows][columns] == 'C')
		vars.img.img_ptr = mlx_xpm_file_to_image(vars.mlx, "images/brain.xpm",
				&vars.img.size.x, &vars.img.size.y);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr,
		SPR_WIDTH * columns, SPR_HEIGHT * rows);
	mlx_destroy_image(vars.mlx, vars.img.img_ptr);
	return (0);
}

int	draw_map(t_vars vars)
{
	int	rows;
	int	columns;

	rows = 0;
	while (rows < vars.map.size.y)
	{
		columns = 0;
		while (columns < vars.map.size.x)
		{
			load_graphics(vars, rows, columns);
			columns++;
		}
		rows++;
	}
	return (0);
}

int	count_points(t_vars *vars)
{
	int	rows;
	int	columns;

	rows = 0;
	vars->game.count_points = 0;
	while (rows < vars->map.size.y)
	{
		columns = 0;
		while (columns <= vars->map.size.x)
		{
			if (vars->map.mtx[rows][columns] == 'C')
				vars->game.count_points++;
			columns++;
		}
		rows++;
	}
	return (vars->game.count_points);
}

int	place_player(t_vars *vars)
{
	int	rows;
	int	columns;

	rows = 0;
	while (rows < vars->map.size.y)
	{
		columns = 0;
		while (columns < vars->map.size.x)
		{
			if (vars->map.mtx[rows][columns] == 'P')
			{
				vars->img.pos.x = columns;
				vars->img.pos.y = rows;
			}
			columns++;
		}
		rows++;
	}
	return (0);
}
