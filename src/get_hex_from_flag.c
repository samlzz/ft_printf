/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_from_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:51:05 by sliziard          #+#    #+#             */
/*   Updated: 2024/11/12 18:59:27 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//* INT EN HEX
t_str	get_hex_int(va_list *args)
{
	return (newstr(
			ft_ltoa_base((long)va_arg(*args, unsigned int), "0123456789abcdef")
		));
}

t_str	get_upperhex_int(va_list *args)
{
	return (newstr(
			ft_ltoa_base((long)va_arg(*args, unsigned int), "0123456789ABCDEF")
		));
}

//* HEX PTR
t_str	get_hex_pointer(va_list *args)
{
	return (newstr(
			ft_ulltoa_base(
				(unsigned long long)va_arg(*args, void *),
				"0123456789abcdef"
			)
		));
}
