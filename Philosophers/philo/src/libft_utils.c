/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:01:28 by dpaal             #+#    #+#             */
/*   Updated: 2022/10/03 17:18:36 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		mns;
	int		nbr;

	i = 0;
	mns = 0;
	nbr = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		mns = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i] - '0');
		i++;
	}
	if (mns == 1)
		nbr = nbr * (-1);
	return (nbr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*set;
	size_t	i;

	ptr = malloc(nmemb * size);
	set = ptr;
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < (nmemb * size))
	{
		set[i] = '\0';
		i++;
	}
	return (ptr);
}
