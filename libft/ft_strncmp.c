/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 20:18:01 by klenesle          #+#    #+#             */
/*   Updated: 2026/10/27 14:13:14 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if ((str1[i] - str2[i]) != 0)
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
