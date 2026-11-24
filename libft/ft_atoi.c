/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:11:42 by klenesle          #+#    #+#             */
/*   Updated: 2026/11/12 16:09:23 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		result;
	int		negative;

	i = 0;
	result = 0;
	negative = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
		negative++;
	if (negative == 1 || nptr[i] == '+')
		i++;
	while (nptr[i] != '\0')
	{
		if (nptr[i] < 48 || nptr[i] > 57)
			break ;
		result *= 10;
		result += nptr[i] % 16;
		i++;
	}
	if (negative == 1)
		result = -result;
	return (result);
}
