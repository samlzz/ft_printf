/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:50:58 by sliziard          #+#    #+#             */
/*   Updated: 2025/01/10 21:20:55 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static void	free_for_quit(va_list *args, t_flag *fdict, char *to_free1)
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
	t_mem	dest;
	ssize_t	writted;

	if (!format)
		return (ERR_VALUE);
	dest.size = ft_strlen(format) + PADDING_BUFF;
	dest.content = malloc(dest.size);
	if (!dest.content)
		return (ERR_VALUE);
	fdict = newflags_dict();
	if (!fdict)
		return (free(dest.content), ERR_VALUE);
	va_start(args, format);
	fill_fstr(format, &dest, fdict, &args);
	if (!dest.content)
		return (free_for_quit(&args, fdict, NULL), ERR_VALUE);
	writted = write(1, dest.content, dest.size);
	free_for_quit(&args, fdict, dest.content);
	if (writted < 0)
		return (ERR_VALUE);
	return (dest.size);
}

bool	put_in_dest(t_mem *dest, t_mem flag, size_t *i, size_t *j)
{
	size_t	alloc_s;

	if (*j + flag.size > dest->size)
	{
		alloc_s = dest->size + flag.size + PADDING_BUFF;
		dest->content = ft_realloc(dest->content, dest->size, alloc_s);
		if (!dest->content)
			return (false);
		dest->size = alloc_s;
	}
	ft_memmove(dest->content + *j, flag.content, flag.size);
	free(flag.content);
	*j += flag.size;
	*i += 1;
	return (true);
}

void	fill_fstr(const char *format, t_mem *dst, t_flag *fdict, va_list *va)
{
	size_t			i;
	size_t			j;
	t_get_str_func	f;

	i = 0;
	j = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			dst->content[j++] = format[i++];
		if (!format[i])
			break ;
		f = flag_to_str(fdict, format[++i]);
		if (!f)
		{
			if (!format[i])
				break ;
			dst->content[j++] = '%';
			continue ;
		}
		if (!put_in_dest(dst, f(va), &i, &j))
			return (free_for_quit(va, fdict, NULL));
	}
	dst->size = j;
}
