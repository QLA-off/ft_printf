/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 08:34:42 by klenesle          #+#    #+#             */
/*   Updated: 2026/11/24 04:10:45 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(long int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_print_u(unsigned int nbr)
{
	int		i;
	int		intlen;
	char	*str;

	intlen = ft_intlen(nbr);
	i = intlen;
	str = malloc(intlen + 1);
	if (str == NULL)
		return (0);
	str[i] = '\0';
	i--;
	if (nbr == 0)
	{
		str[i] = nbr % 10 + '0';
	}
	while (nbr > 0)
	{
		str[i] = nbr % 10 + '0';
		i--;
		nbr /= 10;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (intlen);
}
