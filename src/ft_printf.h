/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:50:16 by sliziard          #+#    #+#             */
/*   Updated: 2025/04/11 14:46:18 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define ERR_VALUE -1

# ifndef PRINTF_PADDING
#  define PRINTF_PADDING 42
# endif

int32_t	ft_printf(const char *format, ...) \
		__attribute__((format(printf, 1, 2)));
int32_t	ft_fprintf(int fd, const char *format, ...) \
		__attribute__((format(printf, 2, 3)));
int32_t	ft_srprintf(char **str, size_t n, const char *format, ...) \
		__attribute__((format(printf, 3, 4)));
int32_t	ft_snprintf(char *str, size_t n, const char *format, ...) \
		__attribute__((format(printf, 3, 4)));

int32_t	ft_vsrprintf(char **str, size_t n, const char *format, va_list ap);
int32_t	ft_vfprintf(int fd, const char *format, va_list ap);

#endif
