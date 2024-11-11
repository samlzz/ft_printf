#include "ftprintf.h"
#include <stdlib.h>
#include <limits.h>

void	nb_to_astr(long nb, t_str *dest, char *base, size_t b_len)
{
	dest->str[dest->len] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		dest->len--;
		dest->str[0] = '-';
	}
	while (dest->len > 0)
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
		dest->len++;
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
char	*ft_itoa(int n)
{
	t_str	*dest;
	char	*n_in_base10;

	dest = init_dest((long)n, 10);
	if (!dest)
		return (NULL);
	nb_to_astr((long)n, dest, "0123456789", 10);
	n_in_base10 = dest->str;
	free(dest);
	return (n_in_base10);
}

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
