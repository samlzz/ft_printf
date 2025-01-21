/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:04:55 by sliziard          #+#    #+#             */
/*   Updated: 2025/01/21 16:59:26 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static bool	_put_in_dest(t_mem *dest, t_mem flag, size_t *i, size_t *j)
{
	size_t	alloc_s;

	if (!flag.content)
		return (false);
	if (*j + flag.size > dest->size - 1)
	{
		alloc_s = dest->size + flag.size + PRINTF_PADDING;
		dest->content = ft_realloc(dest->content, dest->size, alloc_s);
		if (!dest->content)
			return (false);
		dest->content[alloc_s - 1] = 0;
		dest->size = alloc_s;
	}
	ft_strlcat(dest->content, flag.content, dest->size);
	free(flag.content);
	*j += flag.size;
	*i += 1;
	return (true);
}

static void	_fill_fstr(const char *format, t_mem *dst, t_flag *fdict, va_list va)
{
	size_t			i;
	size_t			j;
	t_get_str_func	f;

	(i = 0, j = 0);
	while (format[i])
	{
		while (format[i] != '%' && format[i] && j < dst->size - 1)
			dst->content[j++] = format[i++];
		if (!format[i])
			break ;
		f = flag_to_str(fdict, format[++i]);
		if (!f)
		{
			if (!format[i] || j >= dst->size - 1)
				break ;
			dst->content[j++] = '%';
			continue ;
		}
		if (!_put_in_dest(dst, f(va), &i, &j))
			return ;
	}
	dst->content[j] = 0;
	dst->size = j;
}

int	ft_vsrprintf(char **str, size_t n, const char *format, va_list ap)
{
	t_mem	dest;
	t_flag	fdict[FLAG_NB];

	if (!format)
		return (ERR_VALUE);
	dest.size = ft_strlen(format) + 1;
	if (n < dest.size)
	{
		dest.content = ft_realloc(*str, n, dest.size);
		dest.content[dest.size - 1] = 0;
	}
	else
		dest = (t_mem) {*str, n};
	if (!dest.content)
		return (ERR_VALUE);
	init_flags(fdict);
	_fill_fstr(format, &dest, fdict, ap);
	if (!dest.content)
		return (ERR_VALUE);
	*str = dest.content;
	return (dest.size);
}

int	ft_vfprintf(int fd, const char *format, va_list ap)
{
	t_mem	dest;
	t_flag	fdict[FLAG_NB];
	ssize_t	writted;

	if (!format)
		return (ERR_VALUE);
	dest.size = ft_strlen(format) + PRINTF_PADDING;
	dest.content = ft_calloc(dest.size, sizeof (char));
	if (!dest.content)
		return (ERR_VALUE);
	dest.content[0] = 0;
	init_flags(fdict);
	_fill_fstr(format, &dest, fdict, ap);
	if (!dest.content)
		return (ERR_VALUE);
	writted = write(fd, dest.content, dest.size);
	free(dest.content);
	if (writted < 0)
		return (ERR_VALUE);
	return (dest.size);
}

