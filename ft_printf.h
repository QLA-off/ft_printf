/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 02:49:21 by klenesle          #+#    #+#             */
/*   Updated: 2026/11/23 09:42:52 by klenesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_percent(void);
int	ft_print_c(char c);
int	ft_print_s(char *str);
int	ft_print_p(void *ptr);
int	ft_print_d_i(int nbr);
int	ft_print_u(unsigned int nbr);
int	ft_print_x(unsigned int hex, char format);

#endif // FT_PRINTF_H