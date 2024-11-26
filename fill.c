/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:55:42 by nseon             #+#    #+#             */
/*   Updated: 2024/11/26 16:38:19 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../Libft/libft.h"
#include "printf.h"

/*
fill the malloc
*/

static int	check(const char *format, int i)
{
	i++;
	if (format[i] == 'c' || format[i] == '%' || format[i] == 's'
		|| format[i] == 'p' || format[i] == 'd' || format[i] == 'i'
		|| format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
		return (1);
	else
		return (0);
}

static int	str_fill(char *dst, char *src, int j)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	return (j);
}

static int	fill_format(char c, va_list args, int j, char *tab)
{
	if (c == 'c')
	{
		tab[j] = va_arg(args, int);
		return (j + 1);
	}
	else if (c == '%')
	{
		tab[j] = '%';
		return (j + 1);
	}
	else if (c == 's')
		return (str_fill(tab, va_arg(args, char *), j));
	else if (c == 'd' || c == 'i')
		return (str_fill(tab, ft_itoa(va_arg(args, int)), j));
	else if (c == 'x' || c == 'X')
		return (str_fill(tab, uitoa_base(va_arg(args, unsigned int)
					, c, "0123456789abcdef", 16), j));
	else if (c == 'p')
		return (str_fill(tab, uitoa_base((unsigned long long int)
					va_arg(args, void *), c, "0123456789abcdef", 16), j));
	else if (c == 'u')
		return (str_fill(tab, uitoa_base(va_arg(args, unsigned int)
					, c, "0123456789", 10), j));
	else
		return (0);
}

void	fill(char *tab, const char *format, va_list args)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (format)
	{
		if (format[i] == '%' && check(format, i))
		{
			j = fill_format(format[i + 1], args, j, tab);
			i += 2;
		}
		tab[j] = format[i];
		i++;
		j++;
	}
}
