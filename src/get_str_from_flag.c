/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_from_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:51:08 by sliziard          #+#    #+#             */
/*   Updated: 2024/11/13 22:38:55 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_str	newstr(char *str)
{
	t_str	new;

	new.str = str;
	if (!str)
		new.len = 0;
	else
		new.len = ft_strlen(str);
	return (new);
}

//* CHAR
t_str	get_char(va_list *args)
{
	t_str	result;

	result.len = 0;
	result.str = malloc(sizeof (char));
	if (result.str)
	{
		result.len = 1;
		result.str[0] = (char)va_arg(*args, int);
	}
	return (result);
}

//* %
t_str	get_percent(va_list *args)
{
	(void)args;
	return (newstr(ft_strdup("%")));
}

//* STR
t_str	get_str(va_list *args)
{
	char	*ptr;

	ptr = va_arg(*args, char *);
	if (!ptr)
		return (newstr(ft_strdup("(null)")));
	return (newstr(ft_strdup(ptr)));
}

//* HEX PTR
t_str	get_hex_pointer(va_list *args)
{
	t_str	result;
	char	*hex_val;
	void	*ptr;

	ptr = va_arg(*args, void *);
	if (!ptr)
		return (newstr(ft_strdup("(nil)")));
	hex_val = ft_ulltoa_base((unsigned long long)ptr, "0123456789abcdef");
	result.len = 2 + ft_strlen(hex_val) + 1;
	result.str = malloc(sizeof (char) * result.len);
	if (!result.str)
	{
		result.len = 0;
		return (result);
	}
	ft_strlcpy(result.str, "0x", result.len);
	ft_strlcat(result.str, hex_val, result.len);
	free(hex_val);
	result.len--;
	return (result);
}
