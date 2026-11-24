/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 08:16:18 by klenesle          #+#    #+#             */
/*   Updated: 2026/11/24 04:15:14 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_convert_hex(int nbr, char format)
{
	char	*hnbr;

	if (format == 'x')
	{
		hnbr = "0123456789abcdef";
	}
	if (format == 'X')
	{
		hnbr = "0123456789ABCDEF";
	}
	return (hnbr[nbr]);
}

static int	ft_hexlen(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

int	ft_print_x(unsigned int hex, char format)
{
	int		i;
	int		hexlen;
	char	*str;

	hexlen = ft_hexlen(hex);
	i = hexlen;
	str = malloc(hexlen + 1);
	if (str == NULL)
		return (0);
	str[i] = '\0';
	i--;
	if (hex == 0)
	{
		str[i] = ft_convert_hex(hex % 16, format);
	}
	while (hex > 0)
	{
		str[i] = ft_convert_hex(hex % 16, format);
		i--;
		hex /= 16;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (hexlen);
}
