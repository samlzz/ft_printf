/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:50:16 by sliziard          #+#    #+#             */
/*   Updated: 2025/01/22 15:30:54 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef FTP_FLAGS_H
#  warning "Check your import, 'flags.h' was already included."
# endif

# include "ftp_flags.h"

# define ERR_VALUE -1

# ifndef PRINTF_PADDING
#  define PRINTF_PADDING 42
# endif


int			ft_printf(const char *format, ...) \
			__attribute__((format(printf, 1, 2)));
int			ft_fprintf(int fd, const char *format, ...) \
			__attribute__((format(printf, 2, 3)));
int			ft_srprintf(char **str, size_t n, const char *format, ...) \
			__attribute__((format(printf, 3, 4)));
int			ft_snprintf(char *str, size_t n, const char *format, ...) \
			__attribute__((format(printf, 3, 4)));

int			ft_vsrprintf(char **str, size_t n, const char *format, va_list ap);
int			ft_vfprintf(int fd, const char *format, va_list ap);

#endif
