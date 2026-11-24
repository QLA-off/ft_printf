/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 04:28:05 by klenesle          #+#    #+#             */
/*   Updated: 2026/10/24 06:53:49 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == NULL)
	{
		return (NULL);
	}
	if (start >= ft_strlen(s))
	{
		return (ft_calloc(1, 1));
	}
	if (len > ft_strlen(s) - start)
	{
		len = ft_strlen(s) - start;
	}
	str = malloc(len + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	ft_memset(str, 0, len + 1);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
