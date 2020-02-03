/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:44:05 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/09 13:07:20 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/*
**	Functions Dispatchers
*/
t_parse		parsing(const int ac, char **av);
void		dispatch(t_parse *parse);

/*
**	Functions for Open and Close
*/
int			open_fd(const char *file);
int			open_write_fd(const char *file);
int			close_fd(const int fd);
int			reopen_fd(const int current_fd, const char *file);

/*
**	Functions for get File, Data, or String
*/
t_data		*new_data(void);
t_data		*get_data(const int fd, const char *fd_name);
t_data		*get_file(const int fd, const char *fd_name);
t_data		*get_string(char *s);
void		*get_random(void);
uint8_t		*get_pass(const char *prompt);

/*
**	Functions for Lst_opt
*/
t_opt		*new_opt_fd(t_flags flags, t_data *data, char *fd);
t_opt		*new_opt(t_flags flags, t_data *data);
void		add_to_end_lst(t_opt *new, t_opt **lst);
void		print_lst(t_opt **lst);

/*
**	Functions for Exit, Clean, Error
*/
void		exit_error(void);
void		exit_msg(const char *msg);
void		exit_error_msg(const char *msg);
void		exit_error_free(void **to_free);
void		print_error(const char *msg);
void		print_usage(const int usage_int, const char *command);
void		clean_prog(t_parse *parse);
void		clean_data(t_data **data);

#endif
