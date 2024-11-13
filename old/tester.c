#define BUFF_SIZE 1024

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int ft_vsnprintf(char *buff, size_t size, const char *format, va_list args)
{
	int saved_stdout, return_value;
	int pipe_fd[2]; //? [1]: ecriture | [0]: lecture

	//* rediriger la sortie standart pour capturer l'output de ft_printf
	saved_stdout = dup(STDOUT_FILENO);
	pipe(pipe_fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);

	return_value = ft_printf(format, &args);
	fflush(stdout);

	ssize_t len = read(pipe_fd[0], buff, size - 1);
	if (len < 0) {
		perror("Error reading from pipe");
		return -1;
	}
	buff[len] = 0;

	//* retablir la sortie standart
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	close(pipe_fd[0]);

	return (return_value);
}

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

bool check(int buff, bool ret)
{
	bool succes = false;

	if (buff == 0 && ret)
	{
		printf(GREEN "OK\n");
		succes = true;
	}
	else if (buff == 0)
		printf(YELLOW "Output is same. Not return values\n");
	else if (ret)
		printf(YELLOW "Return values are equal. Not output\n");
	else
		printf(RED "KO\n");
	printf(RESET);
	return succes;
}

void compare_printf(const char *format, ...)
{
	va_list arg, ft_arg;
	char printf_output[BUFF_SIZE];
	char ft_output[BUFF_SIZE];
	int printf_return, ft_return;

	if (strlen(format) > BUFF_SIZE)
	{
		printf("Please increase the buffer size or passed a smaller format");
		return;
	}
	va_start(arg, format);
	va_copy(ft_arg, arg);

	ft_return = ft_vsnprintf(ft_output, BUFF_SIZE, format, ft_arg);
	printf_return = vsnprintf(printf_output, BUFF_SIZE, format, arg);

	if (!check(
			strcmp(printf_output, ft_output),
			printf_return == ft_return))
	{
		printf(CYAN UNDERLINE BOLD "Functions results:\n" RESET);
		printf(WHITE UNDERLINE);
		printf("printf (%d):  "RESET"%s\n", printf_return, printf_output);
		printf(WHITE UNDERLINE);
		printf("ft_printf (%d):  "RESET"%s\n", ft_return, ft_output);
	}
	printf("|Console Output|\n");
	ft_printf(format, arg);
	va_end(arg);
	va_end(ft_arg);
}