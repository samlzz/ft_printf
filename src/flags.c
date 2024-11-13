/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:50:26 by sliziard          #+#    #+#             */
/*   Updated: 2024/11/13 22:48:56 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#define FLAG_NB 9

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

void	init_flags1(t_flag *tab, t_flag *tmp)
{
	tmp->flag = 'c';
	tmp->func = &get_char;
	tab[0] = *tmp;
	tmp->flag = '%';
	tmp->func = &get_percent;
	tab[1] = *tmp;
	tmp->flag = 's';
	tmp->func = &get_str;
	tab[2] = *tmp;
	tmp->flag = 'd';
	tmp->func = &get_int;
	tab[3] = *tmp;
	tmp->flag = 'i';
	tab[4] = *tmp;
	tmp->flag = 'u';
	tmp->func = &get_unsigned_int;
	tab[5] = *tmp;
	tmp->flag = 'x';
	tmp->func = &get_hex_int;
	tab[6] = *tmp;
	tmp->flag = 'X';
	tmp->func = &get_upperhex_int;
	tab[7] = *tmp;
}

void	init_flags2(t_flag *tab, t_flag *tmp)
{
	tmp->flag = 'p';
	tmp->func = &get_hex_pointer;
	tab[8] = *tmp;
}

t_flag	*newflags_dict(void)
{
	t_flag	*dict;
	t_flag	tmp;

	dict = malloc(sizeof(t_flag) * FLAG_NB);
	if (!dict)
		return (NULL);
	init_flags1(dict, &tmp);
	init_flags2(dict, &tmp);
	return (dict);
}
