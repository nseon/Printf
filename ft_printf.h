/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:42:28 by nseon             #+#    #+#             */
/*   Updated: 2024/11/27 09:46:56 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		str_size(const char *format, va_list args);
char	*uitoa_base(unsigned int n, char c, char *base, int div);
void	fill(char *tab, const char *format, va_list args);

#endif
