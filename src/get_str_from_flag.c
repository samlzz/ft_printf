/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_from_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:51:08 by sliziard          #+#    #+#             */
/*   Updated: 2024/11/13 22:08:33 by sliziard         ###   ########.fr       */
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

	result.len = 1;
	result.str = malloc(sizeof (char));
	result.str[0] = (char)va_arg(*args, int);
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
	char	*arg;

	arg = va_arg(*args, char *);
	if (!arg)
		return (newstr(ft_strdup("(null)")));
	return (newstr(ft_strdup(arg)));
}

//* INT
t_str	get_int(va_list *args)
{
	return (newstr(ft_itoa(va_arg(*args, int))));
}
