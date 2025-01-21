/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:50:16 by sliziard          #+#    #+#             */
/*   Updated: 2025/01/21 15:32:12 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "flags.h"

# define ERR_VALUE -1

# ifndef PRINTF_PADDING
#  define PRINTF_PADDING 42
# endif

int			ft_printf(const char *format, ...);
int			ft_fprintf(int fd, const char *format, ...);
int			ft_srprintf(char **str, size_t n, const char *format, ...);
int			ft_snprintf(char *str, size_t n, const char *format, ...);

int			ft_vsrprintf(char **str, size_t n, const char *format, va_list ap);
int			ft_vfprintf(int fd, const char *format, va_list ap);

#endif
