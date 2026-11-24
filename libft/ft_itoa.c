/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 04:33:07 by klenesle          #+#    #+#             */
/*   Updated: 2026/10/27 08:25:07 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getintlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_revstr(char *str)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	if (str[i] == '-')
	{
		i++;
	}
	while (str[i] && i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*result;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc(sizeof(char) * (ft_getintlen(n) + 1));
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		result[i++] = '-';
		n = -n;
	}
	while (n != 0)
	{
		result[i] = (n % 10) + '0';
		i++;
		n /= 10;
	}
	result[i] = '\0';
	ft_revstr(result);
	return (result);
}
