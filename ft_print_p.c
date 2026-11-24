/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 06:07:43 by klenesle          #+#    #+#             */
/*   Updated: 2026/11/24 03:49:43 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void *ptr)
{
	int					i;
	int					printed;
	unsigned long long	address;
	char				*digits;
	char				buf[16];

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	i = 0;
	printed = ft_print_s("0x");
	address = (unsigned long long)ptr;
	digits = "0123456789abcdef";
	while (address > 0)
	{
		i++;
		buf[i] = digits[address % 16];
		address /= 16;
	}
	while (i > 0)
	{
		printed += ft_print_c(buf[i]);
		i--;
	}
	return (printed);
}
