#include "ftprintf.h"

int main(int argc, char const *argv[])
{
	unsigned int  i = 0;
	(void)argv;

	if (argc > 2)
		ft_printf("Hello world ! %s: {%s}%\n", argv[1], argv[2]);
	ft_printf("Argument count: %d: %x || %X\n", argc, argc, argc);
	if (argc > 3)
		while (argv[3][i])
		{
			ft_printf("caractere: [%c] | index: [%u]\n", argv[3][i], i);
			i++;
		}
	if (argc > 4)
		while (*argv[4])
		{
			ft_printf("[%c] a l'adresse: %p\n", *argv[4], argv[4]);
			argv[4]++;
		}
		
	ft_printf("troisieme test %%\ncontinue 3eme test%\n");

	return (0);
}
