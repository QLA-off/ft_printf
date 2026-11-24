/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 00:02:13 by klenesle          #+#    #+#             */
/*   Updated: 2026/10/21 01:28:05 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*destination;
	const char	*source;

	i = 0;
	destination = dest;
	source = src;
	if (destination > source)
	{
		i = n;
		while (0 < i)
		{
			i--;
			destination[i] = source[i];
		}
	}
	else
	{
		while (n > i)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (destination);
}
