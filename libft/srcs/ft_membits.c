/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_membits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:08:47 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/13 16:22:23 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_membits(void *s, size_t len, size_t size)
{
	size_t			i;
	size_t			y;
	unsigned char	*data;
	unsigned char	b;

	data = (unsigned char*)s;
	i = 0;
	while (i <= len)
	{
		y = 0;
		while (y < size)
		{
			b = data[i] >> ((size - y - 1) * 8);
			ft_putbits(data[i++]);
			if (y + 1 != size)
				ft_putchar('-');
			y++;
		}
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
