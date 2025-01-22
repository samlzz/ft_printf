/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_from_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:51:08 by sliziard          #+#    #+#             */
/*   Updated: 2025/01/22 13:40:56 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp_flags.h"
#include <stdlib.h>

t_mem	newstr(char *str)
{
	t_mem	new;

	new.content = str;
	if (!str)
		new.size = 0;
	else
		new.size = ft_strlen(str);
	return (new);
}

//* CHAR
t_mem	get_char(va_list args)
{
	t_mem	result;

	result.size = 0;
	result.content = malloc(sizeof (char) * 2);
	if (result.content)
	{
		result.size = 1;
		result.content[0] = (char)va_arg(args, int);
		result.content[1] = 0;
	}
	return (result);
}

//* %
t_mem	get_percent(va_list args)
{
	(void)args;
	return (newstr(ft_strdup("%")));
}

//* STR
t_mem	get_str(va_list args)
{
	char	*ptr;

	ptr = va_arg(args, char *);
	if (!ptr)
		return (newstr(ft_strdup("(null)")));
	return (newstr(ft_strdup(ptr)));
}

//* HEX PTR
t_mem	get_hex_pointer(va_list args)
{
	t_mem	result;
	char	*hex_val;
	void	*ptr;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (newstr(ft_strdup("(nil)")));
	hex_val = ft_ulltoa_base((unsigned long long)ptr, "0123456789abcdef");
	result.size = 2 + ft_strlen(hex_val) + 1;
	result.content = malloc(sizeof (char) * result.size);
	if (!result.content)
	{
		result.size = 0;
		return (result);
	}
	ft_strlcpy(result.content, "0x", result.size);
	ft_strlcat(result.content, hex_val, result.size);
	free(hex_val);
	result.size--;
	return (result);
}
