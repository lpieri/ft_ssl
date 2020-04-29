/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:13:19 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/29 11:49:08 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DES_H
# define DES_H

# include "../../../libft/include/libft.h"
# include "../../structure.h"

void		*des(void *opt, size_t len_opt);
uint8_t		*des_permute(uint8_t *to_perm, const int *arr, size_t new_len);
void		des_key_schedule(void *key, size_t key_len);

#endif
