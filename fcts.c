/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:50:54 by nseon             #+#    #+#             */
/*   Updated: 2024/11/27 10:16:32 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf.h"

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

char	*uitoa_base(unsigned int n, char c, char *base, int div)
{
	int		i;
	char	*tab;

	i = count(n);
	tab = ft_calloc(count(n) + 1, (sizeof (char)));
	if (tab == NULL)
		return (0);
	while (n > 15)
	{
		tab[--i] = base[n % div];
		if (c == 'X' && 'a' <= tab[i] && tab[i] <= 'f')
			tab[i] -= 32;
		n /= 10;
	}
	tab[i] = base[n];
	return (tab);
}
