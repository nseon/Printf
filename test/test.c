/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:48:09 by nseon             #+#    #+#             */
/*   Updated: 2024/11/28 17:06:51 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main()
{
	int		n;
	char	c;
	char	str[] = "123456789";
	int		test;
	char 	*s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";

	n = INT_MIN;
	c = 'd';
	//test = printf("%%%c%%%p ", 'A', str);
	//printf("return (%d)\n", test);
	test = ft_printf("ou%ciyh||µbqosi<dyfg ",c);
	printf("return (%d)\n", test);
	return (0);
}
