#include "ftprintf.h"
#include <stdlib.h>
#include <limits.h>

bool	valid_base(char *base, size_t *len)
{
	size_t	i;
	size_t	j;

	if (!base)
		return (false);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= ' ')
			return (false);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (false);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (false);
	*len = i;
	return (true);
}

char	*ft_itoa_base(int n, char *base)
{
	t_str	*dest;
	size_t	b_len;
	char	*n_in_b;

	if (!valid_base(base, &b_len))
		return (NULL);
	dest = init_dest((long)n, b_len);
	if (!dest)
		return (NULL);
	nb_to_astr((long)n, dest, base, b_len);
	n_in_b = dest->str;
	free(dest);
	return (n_in_b);
}

char	*ft_ltoa_base(long n, char *base)
{
	t_str	*dest;
	size_t	b_len;
	char	*n_in_b;

	if (!valid_base(base, &b_len))
		return (NULL);
	if (n == LONG_MIN)
	{
		return (ft_strdup("-9223372036854775808"));
	}
	dest = init_dest(n, b_len);
	if (!dest)
		return (NULL);
	nb_to_astr(n, dest, base, b_len);
	n_in_b = dest->str;
	free(dest);
	return (n_in_b);
}

char	*ft_ulltoa_base(unsigned long long n, char *base)
{
	unsigned long long	tmp;
	size_t				base_len;
	t_str				dest;

	if (!valid_base(base, &base_len))
		return (NULL);
	tmp = n;
	dest.len = 1;
	while (tmp >= (unsigned long long)base_len)
	{
		tmp /= (unsigned long long)base_len;
		dest.len++;
	}
	dest.str = malloc(sizeof(char) * (dest.len + 1));
	if (!dest.str)
		return (NULL);
	dest.str[dest.len] = '\0';
	while (dest.len)
	{
		dest.str[--dest.len] = base[n % base_len];
		n /= base_len;
	}
	return (dest.str);
}
