/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:55:42 by nseon             #+#    #+#             */
/*   Updated: 2024/11/26 11:21:58 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../Libft/libft.h"

/*
fill the malloc
*/

void	fill(char *tab, char *format, va_list args)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (format)
	{
		if (format[i] == '%')

		tab[i + j] = format[i];
		i++;
	}
}
void	fill_format(const char *format, va_list args, int j, int i, char *tab)
{
	if (format[i + 1])
}
