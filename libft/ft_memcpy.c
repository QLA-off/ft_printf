/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:30:43 by klenesle          #+#    #+#             */
/*   Updated: 2026/10/23 23:12:15 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*source;
	char		*destination;

	i = 0;
	source = src;
	destination = dest;
	while (n > i)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
