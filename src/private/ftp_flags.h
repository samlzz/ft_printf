/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_flags.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:49:35 by sliziard          #+#    #+#             */
/*   Updated: 2025/04/11 14:43:01 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_FLAGS_H
# define FTP_FLAGS_H

//? for t_mem
# include "private/libft_internal.h"

# ifndef FT_PRINTF_H
#  include "libft.h"
#  include <stdarg.h>
# endif

# define FLAG_NB 9

typedef t_mem	(*t_get_str_func)(va_list args);
typedef struct s_flag
{
	char			flag;
	t_get_str_func	func;
}	t_flag;

t_get_str_func	flag_to_str(t_flag *dict, char flag);
t_flag			*init_flags(t_flag tab[FLAG_NB]);

t_mem			newstr(char *str);
//* Get string from args
t_mem			get_char(va_list args);
t_mem			get_percent(va_list args);
t_mem			get_str(va_list args);
t_mem			get_int(va_list args);

t_mem			get_unsigned_int(va_list args);
t_mem			get_hex_int(va_list args);
t_mem			get_upperhex_int(va_list args);
t_mem			get_hex_pointer(va_list args);

#endif
