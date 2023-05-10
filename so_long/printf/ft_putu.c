/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:21:17 by dpaal             #+#    #+#             */
/*   Updated: 2022/02/28 13:37:01 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	calc_count(unsigned int n)
{
	int				res;
	unsigned int	i;

	res = 0;
	if (n == 0)
		res = 1;
	i = n;
	while (i != 0)
	{
		i = i / 10;
		res++;
	}
	return (res);
}

static void	recurve(unsigned int nb)
{
	unsigned int	i;
	char			c;

	if (nb > 0)
	{
		i = nb % 10;
		nb = nb / 10;
		c = i + '0';
		recurve(nb);
		ft_putchar(c);
	}
}

int	ft_putu(unsigned int i)
{
	if (i == 0)
	{
		ft_putchar('0');
		return (1);
	}
	recurve(i);
	return (calc_count(i));
}
