/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 07:16:49 by klenesle          #+#    #+#             */
/*   Updated: 2026/11/23 08:06:44 by klenesle         ###   ########.fr       */
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

int	ft_print_d_i(int nbr)
{
	ft_putnbr_fd(nbr, 1);
	return (ft_intlen(nbr));
}
