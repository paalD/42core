/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:18:56 by dpaal             #+#    #+#             */
/*   Updated: 2022/09/26 16:46:47 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_vars vars)
{
	int		rows;
	int		columns;

	rows = 0;
	while (rows < vars.map.size.y)
	{
		columns = 0;
		if (rows == 0 || rows == (vars.map.size.y - 1))
		{
			while (columns < vars.map.size.x)
			{
				if (vars.map.mtx[rows][columns] != '1')
					error_msg("Error\n Please check upper and lower walls.\n");
				columns++;
			}
		}
		if (vars.map.mtx[rows][0] != '1'
			|| vars.map.mtx[rows][(vars.map.size.x - 1)] != '1')
			error_msg("Error\n Please check side walls.\n");
		rows++;
	}
	return (0);
}

int	check_objects(t_vars vars)
{
	int		rows;
	int		columns;
	int		valid[3];

	rows = 0;
	while (rows < vars.map.size.y)
	{
		columns = 0;
		while (columns <= vars.map.size.x)
		{
			if (vars.map.mtx[rows][columns] == 'P')
				valid[0] = 1;
			if (vars.map.mtx[rows][columns] == 'E')
				valid[1] = 1;
			if (vars.map.mtx[rows][columns] == 'C')
				valid[2] = 1;
			columns++;
		}
		rows++;
	}
	if (valid[0] != 1 || valid[1] != 1 || valid[2] != 1)
		error_msg("Error\n Map missing P, E or C.\n");
	return (0);
}

int	check_shape(t_vars vars)
{
	int		rows;

	rows = 0;
	while (rows < vars.map.size.y)
	{
		if (((int)ft_strlen(vars.map.mtx[rows])) != (vars.map.size.x)
			&& rows != (vars.map.size.y - 1))
		{
			if (((int)ft_strlen(vars.map.mtx[rows]) - 1) != (vars.map.size.x))
				error_msg("Error\n Map is not a rectangle\n");
		}
		rows++;
	}
	return (0);
}

int	check_map_characters(t_vars vars)
{
	int	rows;
	int	columns;

	rows = 0;
	while (rows < vars.map.size.y)
	{
		columns = 0;
		while (vars.map.mtx[rows][columns] != '\n'
			&& vars.map.mtx[rows][columns] != '\0')
		{
			if (vars.map.mtx[rows][columns] != '0'
				&& vars.map.mtx[rows][columns] != '1'
				&& vars.map.mtx[rows][columns] != 'P'
				&& vars.map.mtx[rows][columns] != 'E'
				&& vars.map.mtx[rows][columns] != 'C')
				error_msg("Error\n Unknown map character.\n");
			columns++;
		}
		rows++;
	}
	return (0);
}

int	check_map(t_vars vars)
{
	check_walls(vars);
	check_objects(vars);
	check_shape(vars);
	check_map_characters(vars);
	return (0);
}
