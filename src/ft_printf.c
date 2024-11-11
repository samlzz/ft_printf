#include "ftprintf.h"
#include <stdlib.h>
#include <unistd.h>

t_flag	*init_printf(size_t format_l, t_str *dest)
{
	dest->len = format_l + PADDING_BUFF;
	dest->str = malloc(dest->len);
	if (!dest->str)
		return (NULL);
	return (newflags_dict());
}

void	free_for_quit(t_printf_context ctx, char *to_free1)
{
	va_end(*ctx.args);
	if (ctx.fdict)
		free(ctx.fdict);
	if (to_free1)
		free(to_free1);
}

void	put_in_dest(t_str *dest, t_str src, size_t *i, size_t *j)
{
	ft_memcpy(dest->str + *j, src.str, src.len);
	*j += src.len;
	free(src.str);
	*i += 1;
}

void	fill_fstr(char *format, t_str *fdest, t_printf_context ctx)
{
	size_t	i;
	size_t	j;
	t_str	tmp;

	t_str (*f)(va_list *);
	i = 0;
	j = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			fdest->str[j++] = format[i++];
		if (!format[i])
			break ;
		f = flag_to_str(ctx.fdict, format[++i]);
		if (!f)
		{
			if (!format[i])
				break ;
			fdest->str[j++] = format[i++];
			continue ;
		}
		tmp = f(ctx.args);
		if (j + tmp.len > fdest->len)
			if (!realloc_str(fdest, tmp.len))
				return (free_for_quit(ctx, tmp.str));
		put_in_dest(fdest, tmp, &i, &j);
	}
	fdest->len = j;
}

int	ft_printf(char *format, ...)
{
	va_list				args;
	t_printf_context	ctx;
	t_str				dest;

	ctx.fdict = init_printf(ft_strlen(format), &dest);
	if (!ctx.fdict)
		return (0);
	va_start(args, format);
	ctx.args = &args;
	fill_fstr(format, &dest, ctx);
	write(1, dest.str, dest.len);
	free_for_quit(ctx, dest.str);
	return (dest.len);
}
