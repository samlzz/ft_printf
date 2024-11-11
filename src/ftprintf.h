#ifndef FTPRINTF_H
# define FTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>

# define PADDING_BUFF 100

int		ft_printf(char *format, ...);

typedef struct s_str
{
	char	*str;
	size_t	len;
}	t_str;

//* Flag 
# define FLAG_NB 8

typedef struct s_flag
{
	char	flag;
	t_str	(*func)(va_list * args);
}	t_flag;

typedef struct s_printf_context
{
	t_flag	*fdict;
	va_list	*args;
}	t_printf_context;

// func
t_str	(*flag_to_str(t_flag *dict, char flag))(va_list *);
t_flag	*newflags_dict(void);

//* Get string from args
t_str	newstr(char *str);
t_str	get_char(va_list *args);
t_str	get_str(va_list *args);
t_str	get_int(va_list *args);
t_str	get_unsigned_int(va_list *args);

t_str	get_hex_int(va_list *args);
t_str	get_upperhex_int(va_list *args);
t_str	get_hex_pointer(va_list *args);

//* Conversion
void	nb_to_astr(long nb, t_str *dest, char *base, size_t b_len);
t_str	*init_dest(long n, size_t base_l);

char	*ft_itoa(int n);
char	*ft_itoa_base(int n, char *base);
char	*ft_ltoa(long n);
char	*ft_ltoa_base(long n, char *base);
char	*ft_ulltoa_base(unsigned long long n, char *base);

//* Utils
void	*ft_realloc(void *ptr, size_t og_size, size_t new_size);
bool	realloc_str(t_str *to_format, size_t flag_str_l);

#endif
