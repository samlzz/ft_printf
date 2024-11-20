/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:50:58 by sliziard          #+#    #+#             */
/*   Updated: 2024/11/20 13:32:28 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	free_for_quit(va_list *args, t_flag *fdict, char *to_free1)
{
	va_end(*args);
	if (fdict)
		free(fdict);
	if (to_free1)
		free(to_free1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flag	*fdict;
	t_str	dest;

	if (!format)
		return (ERR_VALUE);
	dest.len = ft_strlen(format) + PADDING_BUFF;
	dest.str = malloc(dest.len);
	if (!dest.str)
		return (ERR_VALUE);
	fdict = newflags_dict();
	if (!fdict)
		return (free(dest.str), ERR_VALUE);
	va_start(args, format);
	fill_fstr(format, &dest, fdict, &args);
	if (!dest.str)
	{
		free_for_quit(&args, fdict, NULL);
		return (ERR_VALUE);
	}
	write(1, dest.str, dest.len);
	free_for_quit(&args, fdict, dest.str);
	return (dest.len);
}

bool	put_in_dest(t_str *dest, t_str flag, size_t *i, size_t *j)
{
	size_t	alloc_s;

	if (*j + flag.len > dest->len)
	{
		alloc_s = dest->len + flag.len + PADDING_BUFF;
		dest->str = ft_realloc(dest->str, dest->len, alloc_s);
		if (!dest->str)
			return (false);
		dest->len = alloc_s;
	}
	ft_memmove(dest->str + *j, flag.str, flag.len);
	free(flag.str);
	*j += flag.len;
	*i += 1;
	return (true);
}

void	fill_fstr(const char *format, t_str *dst, t_flag *fdict, va_list *va)
{
	size_t			i;
	size_t			j;
	t_get_str_func	f;

	i = 0;
	j = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			dst->str[j++] = format[i++];
		if (!format[i])
			break ;
		f = flag_to_str(fdict, format[++i]);
		if (!f)
		{
			if (!format[i])
				break ;
			dst->str[j++] = '%';
			continue ;
		}
		if (!put_in_dest(dst, f(va), &i, &j))
			return (free_for_quit(va, fdict, NULL));
	}
	dst->len = j;
}
