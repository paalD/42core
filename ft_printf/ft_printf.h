/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:48:48 by dpaal             #+#    #+#             */
/*   Updated: 2022/03/15 11:51:35 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

struct	s_args
{
	va_list	args;
	int		count;
	int		pos;
};

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putint(int i);
int		ft_putu(unsigned int i);
int		ft_putx(unsigned int i);
int		ft_put_capx(unsigned int i);
int		ft_putp(void *p);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);

#endif
