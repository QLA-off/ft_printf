/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 03:33:47 by klenesle          #+#    #+#             */
/*   Updated: 2026/10/27 14:21:51 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;

	sdup = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (sdup == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(sdup, s, ft_strlen(s) + 1);
	return (sdup);
}
