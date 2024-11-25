/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:16:50 by nseon             #+#    #+#             */
/*   Updated: 2024/11/25 17:02:15 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "printf.h"

int ft_printf(const char *format, ...)
{
	va_list	args;
	va_list args_bis;
	int		len;
	char	*tab;

	va_start(args, format);
	args_bis = args;
	len = str_size(format, args);
	tab = malloc(len * sizeof(char) + 1);


	return (len);
}

#include <stdio.h>

int	main()
{
	int		n;
	char	c;
	char	*str;
	int		test;

	n = -9556;
	c = 'c';
	str = "test+++4";
	test = ft_printf("%%123%d %%456789%s", n, str);
	printf("%d", test);
}
