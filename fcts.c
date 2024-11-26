/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:50:54 by nseon             #+#    #+#             */
/*   Updated: 2024/11/26 15:21:38 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "printf.h"

static int	count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n >= 1)
	{
		count++;
		n /= 16;
	}
	if (count == 0)
		count++;
	return (count);
}

char	*hex_itoa(unsigned int n, char c)
{
	int		i;
	char	*tab;
	int		po;

	po = 0;
	if (c == 'p')
		po = 2;
	i = count(n);
	tab = ft_calloc(count(n) + 1 + po, (sizeof (char)));
	if (c == 'p')
	{
		tab[0] = '0';
		tab[1] = 'x';
	}
	if (tab == NULL)
		return (0);
	while (n > 15)
	{
		tab[--i] = "0123456789abcdef"[n % 16];
		if (c == 'X' && 'a' <= tab[i] && tab[i] <= 'f')
			tab[i] -= 32;
		n /= 10;
	}
	tab[i] = "0123456789abcdef"[n];
	return (tab);
}
