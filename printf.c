/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:16:50 by nseon             #+#    #+#             */
/*   Updated: 2024/11/27 14:00:42 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	args_bis;
	int		len;
	char	*tab;

	va_start(args, format);
	va_start(args_bis, format);
	len = str_size(format, args);
	tab = malloc(len * sizeof(char) + 1);
	if (tab == NULL)
		return (0);
	fill(tab, format, args_bis, len);
	write(1, &tab, len);
	free(tab);
	return (len);
}
