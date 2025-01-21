/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_from_flag2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:51:05 by sliziard          #+#    #+#             */
/*   Updated: 2025/01/21 10:38:06 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//* INT
t_mem	get_int(va_list args)
{
	return (newstr(ft_itoa(va_arg(args, int))));
}

//* UNSIGNED INT
t_mem	get_unsigned_int(va_list args)
{
	return (newstr(
			ft_ltoa((long)va_arg(args, unsigned int))
		));
}

//* INT EN HEX
t_mem	get_hex_int(va_list args)
{
	return (newstr(
			ft_ltoa_base((long)va_arg(args, unsigned int), "0123456789abcdef")
		));
}

t_mem	get_upperhex_int(va_list args)
{
	return (newstr(
			ft_ltoa_base((long)va_arg(args, unsigned int), "0123456789ABCDEF")
		));
}
