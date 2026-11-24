/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 23:24:55 by klenesle          #+#    #+#             */
/*   Updated: 2026/10/24 00:11:12 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == 0)
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && i < len)
	{
		while (big[i] != '\0' && big[i] == little[j] && i < len)
		{
			i++;
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)big + (i - j));
		}
		i -= j;
		i++;
		j = 0;
	}
	return (NULL);
}
