/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:23:31 by sliziard          #+#    #+#             */
/*   Updated: 2025/01/22 13:41:21 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp_flags.h"

t_get_str_func	flag_to_str(t_flag *dict, char flag)
{
	unsigned int	i;

	i = 0;
	while (i < FLAG_NB)
	{
		if (dict[i].flag == flag)
			return (dict[i].func);
		i++;
	}
	return (NULL);
}

/*
* %:
?	c [char]
?	s [string]
?	p [pointer hex]
?	d | i [int]
?	u [unsigned int]
?	x / X [int hex (lower / upper)]
?	% [afficher %]
*/

t_flag	*init_flags(t_flag tab[FLAG_NB])
{
	tab[0] = (t_flag) {'c', &get_char};
	tab[1] = (t_flag) {'%', &get_percent};
	tab[2] = (t_flag) {'s', &get_str};
	tab[3] = (t_flag) {'d', &get_int};
	tab[4] = (t_flag) {'i', &get_int};
	tab[5] = (t_flag) {'u', &get_unsigned_int};
	tab[6] = (t_flag) {'x', &get_hex_int};
	tab[7] = (t_flag) {'X', &get_upperhex_int};
	tab[8] = (t_flag) {'p', &get_hex_pointer};
	return (tab);
}
