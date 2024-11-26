/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:55:42 by nseon             #+#    #+#             */
/*   Updated: 2024/11/26 15:20:12 by nseon            ###   ########.fr       */
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
		{
			j = fill_format(format[i + 1], args, j, tab);
			i += 2;
		}
		tab[j] = format[i];
		i++;
		j++;
	}
}
int	fill_format(char c, va_list args, int j, char *tab)
{
	unsigned long long int	nb;

	if (c == 'c')
	{
		tab[j] == va_arg(args, int);
		return (j + 1);
	}
	else if (c == '%')
	{
		tab[j] = '%';
		return (j + 1);
	}
	else if (c == 's')
		str_fill(tab, va_arg(args, char *), j);
	else if (c == 'd' || c == 'i')
		str_fill(tab, ft_itoa(va_arg(args, int)), j);
	else if (c == 'x' || c == 'X')
		str_fill(tab, hex_itoa(va_arg(args, unsigned int), c), j);
	else if (c == 'p')
		str_fill(tab, hex_itoa(va_arg(args, void *)), j);

}

int	str_fill(char *dst, char *src, int j)
{
	int	i;

	j = 0;
	while (src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	return (j);
}
