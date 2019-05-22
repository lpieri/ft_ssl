/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:12:05 by cpieri            #+#    #+#             */
/*   Updated: 2019/05/22 10:41:33 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash/hash.h"

char	*hex2sum(uint32_t *h, size_t nb_h)
{
	char	*sum;
	char	*tmp;
	size_t	i;

	i = -1;
	if (!(sum = (char*)ft_memalloc(sizeof(char) * ((nb_h * 8) + 1))))
		return (NULL);
	while (++i < nb_h)
	{
		if ((tmp = ft_hex2char(h[i])) == NULL)
			break ;
		ft_strncpy((sum + ft_strlen(sum)), tmp, ft_strlen(tmp));
		ft_memdel((void**)&tmp);
	}
	ft_memdel((void**)&h);
	return (sum);
}