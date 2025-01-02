/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:50:16 by sliziard          #+#    #+#             */
/*   Updated: 2025/01/02 12:05:32 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>

# define PADDING_BUFF 100
# define ERR_VALUE -1

int				ft_printf(const char *format, ...);

//* Flag 
typedef t_mem	(*t_get_str_func)(va_list * args);

typedef struct s_flag
{
	char			flag;
	t_get_str_func	func;
}	t_flag;

// func
t_get_str_func	flag_to_str(t_flag *dict, char flag);
t_flag			*newflags_dict(void);

//* Get string from args
t_mem			newstr(char *str);
t_mem			get_char(va_list *args);
t_mem			get_percent(va_list *args);
t_mem			get_str(va_list *args);
t_mem			get_int(va_list *args);

t_mem			get_unsigned_int(va_list *args);
t_mem			get_hex_int(va_list *args);
t_mem			get_upperhex_int(va_list *args);
t_mem			get_hex_pointer(va_list *args);

//* Conversion
void			nb_to_astr(long nb, t_mem *dest, char *base, size_t b_len);
t_mem			*init_dest(long n, size_t base_l);

char			*ft_itoa(int n);
char			*ft_itoa_base(int n, char *base);
char			*ft_ltoa(long n);
char			*ft_ltoa_base(long n, char *base);
char			*ft_ulltoa_base(unsigned long long n, char *base);

//* Utils
void			*ft_realloc(void *ptr, size_t og_size, size_t new_size);
void			fill_fstr(const char *format, t_mem *dst, \
					t_flag *fdict, va_list *va);

#endif
