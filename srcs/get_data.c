/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:54 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/08 17:54:43 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

char	*get_data(const int fd)
{
	char			buffer[BUFF_SIZE + 1];
	static char		*data = NULL;
	char			*tmp;
	int				nb_read;

	while ((nb_read = read(fd, buffer, BUFF_SIZE)))
	{
		if (data == NULL)
			data = ft_strdup(buffer);
		else
		{
			tmp = data;
			data = ft_strjoin(tmp, buffer);
			ft_strdel(&tmp);
		}
	}
	return (data);
}
