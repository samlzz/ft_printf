/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:52:18 by sliziard          #+#    #+#             */
/*   Updated: 2025/01/21 17:01:46 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret_val;

	va_start(args, format);
	ret_val = ft_vfprintf(1, format, args);
	va_end(args);
	return (ret_val);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		ret_val;

	va_start(args, format);
	ret_val = ft_vfprintf(fd, format, args);
	va_end(args);
	return (ret_val);
}

int	ft_srprintf(char **str, size_t n, const char *format, ...)
{
	va_list	args;
	int		ret_val;

	va_start(args, format);
	ret_val = ft_vsrprintf(str, n, format, args);
	va_end(args);
	return (ret_val);
}

int	ft_snprintf(char *str, size_t n, const char *format, ...)
{
	va_list	args;
	int		ret_val;
	char	*formated;

	if (!str || !n)
		return (ERR_VALUE);
	formated = ft_calloc(n, sizeof (char));
	if (!formated)
		return (ERR_VALUE);
	va_start(args, format);
	ret_val = ft_vsrprintf(&formated, n, format, args);
	va_end(args);
	if (ret_val == ERR_VALUE)
	{
		free(formated);
		return (ret_val);
	}
	if ((size_t)ret_val < n)
		ft_strlcpy(str, formated, ret_val);
	else
		ft_strlcpy(str, formated, n);
	free(formated);
	return (ret_val);
}
