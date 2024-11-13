/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:51:01 by sliziard          #+#    #+#             */
/*   Updated: 2024/11/13 14:21:00 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

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
