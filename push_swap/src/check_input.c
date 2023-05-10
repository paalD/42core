/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:20:48 by dpaal             #+#    #+#             */
/*   Updated: 2022/05/22 18:35:12 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_chars(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == 45)
		{
			if (!argv[i][1])
				return (0);
			j++;
		}
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_max_int(int argc, char **argv)
{
	int		i;
	int		j;
	char	**ptr;

	ptr = argv;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (ptr[i][j] != '\0')
			j++;
		if (j > 11)
			return (0);
		if (j == 11 && (ptr[i][0] != '-' || ft_atolli(ptr[i]) < -2147483648))
			return (0);
		if (j == 10 && ptr[i][0] != '-' && ft_atolli(ptr[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

static int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i < (argc - 1))
	{
		while (j < argc)
		{
			if (ft_atolli(argv[i]) == ft_atolli(argv[j]))
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	check_input(int argc, char **argv)
{
	if (!check_chars(argc, argv))
	{
		write(2, "Error\n", 6);
		exit(0);
		return (0);
	}
	if (!check_max_int(argc, argv))
	{
		write(2, "Error\n", 6);
		exit(0);
		return (0);
	}
	if (!check_duplicates(argc, argv))
	{
		write(2, "Error\n", 6);
		exit(0);
		return (0);
	}
	else
		return (1);
}
