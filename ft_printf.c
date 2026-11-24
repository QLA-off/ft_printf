/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 02:41:48 by klenesle          #+#    #+#             */
/*   Updated: 2026/11/23 09:42:58 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printformat(va_list arguments, char format)
{
	int	printed;

	printed = 0;
	if (format == '%')
		printed += ft_print_percent();
	if (format == 'c')
		printed += ft_print_c(va_arg(arguments, int));
	if (format == 's')
		printed += ft_print_s(va_arg(arguments, char *));
	if (format == 'p')
		printed += ft_print_p(va_arg(arguments, void *));
	if (format == 'd' || format == 'i')
		printed += ft_print_d_i(va_arg(arguments, int));
	if (format == 'u')
		printed += ft_print_u(va_arg(arguments, unsigned int));
	if (format == 'x' || format == 'X')
		printed += ft_print_x(va_arg(arguments, unsigned int), format);
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		printed;
	va_list	arguments;

	i = 0;
	printed = 0;
	va_start(arguments, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			printed += ft_printformat(arguments, str[i]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			printed++;
		}
	}
	va_end(arguments);
	return (printed);
}
