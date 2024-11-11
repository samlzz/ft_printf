#include "ftprintf.h"

t_str	newstr(char *str)
{
	t_str	new;

	new.str = str;
	if (!str)
		new.len = 0;
	else
		new.len = ft_strlen(str);
	return (new);
}

//* CHAR
t_str	get_char(va_list *args)
{
	char	str[2];

	str[0] = (char)va_arg(*args, int);
	str[1] = 0;
	return (newstr(ft_strdup(str)));
}

//* STR
t_str	get_str(va_list *args)
{
	char	*arg;

	arg = va_arg(*args, char *);
	if (!arg)
		return (newstr(ft_strdup("(null)")));
	return (newstr(ft_strdup(arg)));
}

//* INT
t_str	get_int(va_list *args)
{
	return (newstr(ft_itoa(va_arg(*args, int))));
}

//* UNSIGNED INT
t_str	get_unsigned_int(va_list *args)
{
	return (newstr(
			ft_ltoa((long)va_arg(*args, unsigned int))
		));
}
