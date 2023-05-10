/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:39:54 by dpaal             #+#    #+#             */
/*   Updated: 2022/03/15 12:06:15 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	calc_p_size(unsigned long int i)
{
	unsigned long int	len;

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

static void	recurve(unsigned long int nb)
{
	unsigned long int	i;
	char				c;

	if (nb > 0)
	{
		i = nb % 16;
		nb = nb / 16;
		if (i < 10)
			c = i + '0';
		else
			c = i + 87;
		recurve(nb);
		ft_putchar(c);
	}
}

int	ft_putp(void *p)
{
	unsigned long int	i;

	i = (unsigned long int)p;
	if (!p)
		return (ft_putstr("0x0"));
	ft_putstr("0x");
	recurve(i);
	return (calc_p_size(i) + 2);
}
