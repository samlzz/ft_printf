/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:50:51 by sliziard          #+#    #+#             */
/*   Updated: 2024/11/12 18:59:27 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <limits.h>

void	nb_to_astr(long nb, t_str *dest, char *base, size_t b_len)
{
	dest->str[dest->len] = '\0';
	if (nb == 0)
	{
		dest->str[0] = base[0];
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		dest->str[0] = '-';
	}
	while (nb)
	{
		dest->str[--dest->len] = base[nb % b_len];
		nb /= b_len;
	}
}

t_str	*init_dest(long n, size_t base_l)
{
	t_str	*dest;

	dest = malloc(sizeof (t_str));
	if (!dest)
		return (NULL);
	dest->len = 0;
	if (n <= 0)
	{
		dest->len = 1;
		if (n)
			n = -n;
	}
	while (n)
	{
		n /= base_l;
		dest->len++;
	}
	dest->str = malloc(sizeof (char) * (dest->len + 1));
	if (!dest->str)
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
	t_str	*dest;
	char	*n_in_base10;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	dest = init_dest(n, 10);
	if (!dest)
		return (NULL);
	nb_to_astr(n, dest, "0123456789", 10);
	n_in_base10 = dest->str;
	free(dest);
	return (n_in_base10);
}
