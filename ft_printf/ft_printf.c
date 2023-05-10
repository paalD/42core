/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:48:51 by dpaal             #+#    #+#             */
/*   Updated: 2022/02/28 14:17:52 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_handle(va_list args, char flag)
{
	int	count;

	count = 0;
	if (flag == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (flag == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (flag == 'p')
		count += ft_putp(va_arg(args, void *));
	else if (flag == 'i' || flag == 'd')
		count += ft_putint(va_arg(args, int));
	else if (flag == 'u')
		count += ft_putu(va_arg(args, unsigned int));
	else if (flag == 'x')
		count += ft_putx(va_arg(args, unsigned int));
	else if (flag == 'X')
		count += ft_put_capx(va_arg(args, unsigned int));
	else if (flag == '%')
		count += ft_putchar(flag);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int				res;
	struct s_args	*args;

	args = malloc(sizeof(struct s_args));
	va_start(args->args, format);
	args->count = 0;
	args->pos = 0;
	if (format == NULL)
		return (-1);
	while (format[args->pos] != '\0')
	{
		if (format[args->pos] != '%')
			args->count += write(1, &format[args->pos], 1);
		else
		{
			args->pos++;
			args->count += flag_handle(args->args, format[args->pos]);
		}
		args->pos++;
	}
	va_end(args->args);
	res = args->count;
	free(args);
	return (res);
}
