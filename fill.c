/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:55:42 by nseon             #+#    #+#             */
/*   Updated: 2024/11/27 14:03:58 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "Libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

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

static int	str_fill(char *dst, char *src, int j, char c)
{
	int	i;
	int	check;

	check = 1;
	i = 0;
	if (c == 's')
		check = 0;
	while (src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (check == 1)
		free(src);
	return (j);
}

int	fill_char(char *tab, char c, int j)
{
	tab[j] = c;
	return (j + 1);
}

static int	fill_format(char c, va_list args, int j, char *tab)
{
	if (c == 'c')
		return (fill_char(tab, c, j));
	else if (c == '%')
		return (fill_char(tab, '%', j));
	else if (c == 's')
		return (str_fill(tab, va_arg(args, char *), j, c));
	else if (c == 'd' || c == 'i')
		return (str_fill(tab, ft_itoa(va_arg(args, int)), j, c));
	else if (c == 'x' || c == 'X')
		return (str_fill(tab, uitoa_base(va_arg(args, unsigned int)
					, c, "0123456789abcdef", 16), j, c));
	else if (c == 'p')
	{
		tab[j] = '0';
		tab[++j] = 'X';
		return (str_fill(tab, uitoa_base((unsigned long long int)
					va_arg(args, void *), c, "0123456789abcdef", 16), ++j, c));
	}
	else if (c == 'u')
		return (str_fill(tab, uitoa_base(va_arg(args, unsigned int)
					, c, "0123456789", 10), j, c));
	return (0);
}

#include <stdio.h>

void	fill(char *tab, const char *format, va_list args, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (format && j <= len)
	{
		if (format[i] == '%' && check(format, i))
		{
			j = fill_format(format[i + 1], args, j, tab);
			i += 2;
		}
		printf("tab : |%s|\nj : %d\n", &tab[0], j);
		tab[j] = format[i];
		i++;
		j++;
	}
}
