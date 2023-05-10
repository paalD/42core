/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:10:13 by dpaal             #+#    #+#             */
/*   Updated: 2022/03/15 11:51:03 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putint(int i)
{
	int		ret;
	char	*printi;

	ret = 0;
	printi = ft_itoa(i);
	ret = ft_strlen(printi);
	ft_putstr(printi);
	free(printi);
	return (ret);
}
