/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:08:10 by dpaal             #+#    #+#             */
/*   Updated: 2022/09/27 15:03:13 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *msg)
{
	ft_printf(msg);
	exit(1);
}

int	mlx_close(t_vars *vars)
{
	complete_game(vars, "Program closed\n");
	return (0);
}

int	initialize_map(t_vars *vars, char **argv)
{
	int		fd;
	int		rows;
	char	*line;

	vars->map.mtx = malloc(sizeof(char *) * (vars->map.size.y + 1));
	vars->map.mtx[vars->map.size.y] = NULL;
	vars->game.count_steps = 1;
	rows = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_msg("Error\n No map available\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		vars->map.mtx[rows] = line;
		rows++;
		line = get_next_line(fd);
	}
	close(fd);
	check_map(*vars);
	return (0);
}

int	get_map_size(t_vars *vars, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	vars->map.size.x = 0;
	vars->map.size.y = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_msg("Error\n No map file found");
	line = get_next_line(fd);
	while (line)
	{
		vars->map.size.x = ft_strlen(line);
		vars->map.size.y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	check_arg(int argc, char **argv)
{
	if (argc < 2)
		error_msg("Error\n Not enough arguments!\n");
	if (argc > 2)
		error_msg("Error\n Too many arguments!\n");
	if (argc == 2 && \
		ft_strnstr(argv[1], ".ber", (int)ft_strlen(argv[1])) == NULL)
		error_msg("Error\n Map not <.ber> file!\n");
	return (0);
}
