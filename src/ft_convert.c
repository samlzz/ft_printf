/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:50:51 by sliziard          #+#    #+#             */
/*   Updated: 2025/01/02 12:01:37 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <limits.h>

void	nb_to_astr(long nb, t_mem *dest, char *base, size_t b_len)
{
	dest->content[dest->size] = '\0';
	if (nb == 0)
	{
		dest->content[0] = base[0];
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		dest->content[0] = '-';
	}
	while (nb)
	{
		dest->content[--dest->size] = base[nb % b_len];
		nb /= b_len;
	}
}

t_mem	*init_dest(long n, size_t base_l)
{
	t_mem	*dest;

	dest = malloc(sizeof (t_mem));
	if (!dest)
		return (NULL);
	dest->size = 0;
	if (n <= 0)
	{
		dest->size = 1;
		if (n)
			n = -n;
	}
	while (n)
	{
		n /= base_l;
		dest->size++;
	}
	dest->content = malloc(sizeof (char) * (dest->size + 1));
	if (!dest->content)
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}

//* INT
//? ft_itoa in libft

//* LONG
char	*ft_ltoa(long n)
{
	t_mem	*dest;
	char	*n_in_base10;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	dest = init_dest(n, 10);
	if (!dest)
		return (NULL);
	nb_to_astr(n, dest, "0123456789", 10);
	n_in_base10 = dest->content;
	free(dest);
	return (n_in_base10);
}
