/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:42:28 by nseon             #+#    #+#             */
/*   Updated: 2024/11/26 16:09:48 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

int		str_size(const char *format, va_list args);
char	*uitoa_base(unsigned int n, char c, char *base, int div);
void	fill(char *tab, const char *format, va_list args);

#endif
