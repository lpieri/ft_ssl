/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symmetric_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:04:37 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/20 10:34:02 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "symmetric/symmetric.h"
#include <unistd.h>

static const t_sym_opt	g_sym_opt[] =
{
	{'a', e_sym_opt_a, get_sym_opt_a},
	{'d', e_sym_opt_d, get_sym_opt_d},
	{'e', e_sym_opt_e, get_sym_opt_e},
	{'i', e_sym_opt_i, get_sym_opt_i},
	{'o', e_sym_opt_o, get_sym_opt_o},
	{'k', e_sym_opt_k, get_sym_opt_k},
	{'s', e_sym_opt_s, get_sym_opt_s},
	{'p', e_sym_opt_p, get_sym_opt_p},
	{'v', e_sym_opt_v, get_sym_opt_v},
	{0, 0, NULL}
};

static const t_evp_f	g_evp_f[] =
{
	{evp_bytes2key, {8, 8, 32}, 1, EVP_MD5},
	{pbkdf2, {8, 8, 16}, 10000, HMAC_SHA256},
	{NULL, {0, 0, 0}, 0, 0}
};

static void		check_pbkdf2(t_evp **k, uint do_pbkdf2)
{
	t_evp_f		evp_f;

	evp_f = (do_pbkdf2 == 1) ? g_evp_f[1] : g_evp_f[0];
	if (*k != NULL)
	{
		if ((*k)->pass == NULL)
		{
			(*k)->pass = get_pass("enter your password: ");
			(*k)->pass_len = ft_strlen((*k)->pass);
			if ((*k)->salt == NULL)
			{
				(*k)->salt = get_random();
				(*k)->salt_len = ft_strlen((char*)(*k)->salt);
			}
		}
		if ((*k)->key != 0 && (*k)->vect == 0)
			exit_msg("iv undefined");
		else if ((*k)->key == 0 && (*k)->vect == 0)
			evp_f.f(*k, evp_f.c, evp_f.full_size, evp_f.prf);
	}
	else
	{
		*k = new_t_evp(get_pass("enter your password: "), 0, 0, 0);
		evp_f.f(*k, evp_f.c, evp_f.full_size, evp_f.prf);
	}
}

static void		get_sym_opt(char **av, int *now, t_opt *opt, t_evp **k)
{
	size_t		len_now;
	size_t		i;
	size_t		y;

	i = 0;
	len_now = ft_strlen(av[*now]);
	while (++i < len_now)
	{
		y = 0;
		while (g_sym_opt[y].opt != 0)
		{
			if (g_sym_opt[y].opt == av[*now][i])
				if (g_sym_opt[y].sym_opt_fun != NULL)
					g_sym_opt[y].sym_opt_fun(av, now, opt, k);
			y++;
		}
	}
}

static t_opt	*get_sym_args(const int ac, char **av, int now)
{
	t_opt		opt;
	uint		do_pbkdf2;
	t_evp		*k;

	k = NULL;
	do_pbkdf2 = 0;
	opt = (t_opt){NULL, {0, 0, 0, 0, 0, 0}, NULL};
	while (now < ac)
	{
		if (ft_strcmp(av[now], "-pbkdf2") == 0)
			do_pbkdf2 = 1;
		else if (av[now][0] == '-')
			get_sym_opt(av, &now, &opt, &k);
		now++;
	}
	check_pbkdf2(&k, do_pbkdf2);
	print_evp(k);
	get_sym_stdin(&opt, &k);
	return (new_opt(opt.flags, opt.data));
}

t_opt			*symmetric_opts(const int ac, char **av, t_opt *opts, int now)
{
	t_opt	*new;

	new = get_sym_args(ac, av, now);
	add_to_end_lst(new, &opts);
	// print_lst(&opts);
	// while (1);
	return (opts);
}
