#include <stdlib.h>
#include "ftprintf.h"

void	*ft_realloc(void *ptr, size_t og_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (new_size)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr || !ptr)
			return (new_ptr);
		if (new_size < og_size)
			ft_memcpy(new_ptr, ptr, new_size);
		else
			ft_memcpy(new_ptr, ptr, og_size);
	}
	free(ptr);
	return (new_ptr);
}

bool	realloc_str(t_str *to_format, size_t flag_str_l)
{
	size_t	alloc_s;

	alloc_s = to_format->len + flag_str_l + PADDING_BUFF;
	to_format->str = ft_realloc(to_format->str, to_format->len, alloc_s);
	if (!to_format->str)
		return (false);
	to_format->len = alloc_s;
	return (true);
}
