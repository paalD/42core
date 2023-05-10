/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_capx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:30:50 by dpaal             #+#    #+#             */
/*   Updated: 2022/02/28 13:52:00 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	calc_x_size(unsigned int i)
{
	size_t	len;

	len = 0;
	if (i < 16)
		return (1);
	while (i > 0)
	{
		i /= 16;
		len++;
	}
	return (len);
}

static void	recurve(unsigned int nb)
{
	int		i;
	char	c;

	if (nb > 0)
	{
		i = nb % 16;
		nb = nb / 16;
		if (i < 10)
			c = i + '0';
		else
			c = i + 55;
		recurve(nb);
		ft_putchar(c);
	}
}

int	ft_put_capx(unsigned int i)
{
	if (i == 0)
	{
		ft_putchar('0');
		return (1);
	}
	recurve(i);
	return (calc_x_size(i));
}
