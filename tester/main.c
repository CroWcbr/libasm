#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>

#include "libasm.h"

#define COUNT	10000
#define RESET	"\x1B[0m"
#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"

void	test_result(int result)
{
	if (result)
		printf(GREEN "OK" RESET "\n");
	else
		printf(RED "FAILED" RESET "\n");
}

void	test_strlen()
{
	for (int i = 0; i < COUNT; ++i)
	{
		int size = rand() % COUNT;
		char str[size + 1];
		for (int j = 0; j < size; ++j)
			str[j] = rand() % 127 + 1;
		str[size] = '\0';
		int a = ft_strlen(str);
		int b = strlen(str);
		(void)str;
		if (a != b)
		{
			test_result(0);
			return ;
		}
	}
	test_result(1);
}

void	test_strcpy()
{
	for (int i = 0; i < COUNT; ++i)
	{
		int size = rand() % COUNT;
		char str[size + 1];
		char result_a[size + 1];
		char result_b[size + 1];
		for (int j = 0; j < size; ++j)
			str[j] = rand() % 127 + 1;
		str[size] = '\0';
		char* a = ft_strcpy(result_a, str);
		char* b = strcpy(result_b, str);
		if (a != result_a || b != result_b || strcmp(a, b))
		{
			test_result(0);
			return ;
		}
	}
	test_result(1);
}

void	test_strcmp()
{
	for (int i = 0; i < COUNT; ++i)
	{
		int size = rand() % COUNT;
		char str_a[size + 1];
		char str_b[size + 1];
		for (int j = 0; j < size; ++j)
		{
			str_a[j] = rand() % 127 + 1;
			str_b[j] = rand() % 127 + 1;
		}
		str_a[size] = '\0';
		str_b[size] = '\0';
		int a = ft_strcmp(str_a, str_b);
		int b = strcmp(str_a, str_b);
		if (a != b)
		{
			test_result(0);
			return ;
		}
		a = ft_strcmp(str_a, str_a);
		b = strcmp(str_a, str_a);
		if (a != b)
		{
			test_result(0);
			return ;
		}
	}
	test_result(1);
}

void	test_write()
{
	int flag = 1;
	char*	file_a = "test_a";
	char*	file_b = "test_b";
	int fd_a = open(file_a, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_a < 0)
		perror("Cannot open fail for test!");
	int fd_b = open(file_b, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_b < 0)
		perror("Cannot open fail for test!");
	int stdin_backup = dup(0);
	int stdout_backup = dup(1);
	int stderr_backup = dup(2);
	for (int i = 0; i < COUNT; ++i)
	{
		int size = rand() % COUNT;
		int fd = rand() % 10 - 5;
		if (fd == fd_a || fd == fd_b)
			continue;
		char str[size + 1];
		for (int j = 0; j < size; ++j)
			str[j] = rand() % 127 + 1;
		str[size] = '\0';

		errno = 0;
		dup2(fd_a, 0);
		dup2(fd_a, 1);
		dup2(fd_a, 2);
		int a = ft_write(fd, str, size);
		int a_err = errno;

		errno = 0;
		dup2(fd_b, 0);
		dup2(fd_b, 1);
		dup2(fd_b, 2);
		int b = write(fd, str, size);
		int b_err = errno;

		errno = 0;
		if (a != b || a_err != b_err)
		{
			flag = 0;
			break;
		}
	}
	dup2(stdin_backup, 0);	
	dup2(stdout_backup, 1);
	dup2(stderr_backup, 2);
	close(fd_a);
	close(fd_b);

	char command[1024];
	snprintf(command, sizeof(command), "diff %s %s", file_a, file_b);
	int result = system(command);
	if (result)
		flag = 0;

	remove(file_a);
	remove(file_b);
	test_result(flag);
}

void	test_read()
{
	char *large_file_a = "large_file_a.txt";
	char *large_file_b = "large_file_b.txt";
	const char *command_create_file = "dd if=/dev/urandom of=large_file_a.txt bs=1M count=1 >/dev/null 2>&1";
	int result = system(command_create_file);
	(void)result;
	if (result)
		perror("Cannot create fail for test!");
	const char *command_copy_file = "cp large_file_a.txt large_file_b.txt";
	result = system(command_copy_file);
	if (result)
		perror("Cannot copy fail for test!");

	int flag = 1;
	int fd_a = open(large_file_a, O_RDONLY);
	if (fd_a < 0)
		perror("Cannot open fail for test!");
	int fd_b = open(large_file_b, O_RDONLY);
	if (fd_b < 0)
		perror("Cannot open fail for test!");

	for (int i = 0; i < COUNT; ++i)
	{
		int size = rand() % COUNT;
		char str_a[size];
		char str_b[size];

		errno = 0;
		int a = ft_read(fd_a, str_a, size);
		int a_err = errno;

		errno = 0;
		int b = read(fd_b, str_b, size);
		int b_err = errno;

		if (a != b || a_err != b_err || (a_err == 0 && strncmp(str_a, str_b, a)))
		{
			flag = 0;
			break;
		}

		errno = 0;
		a = ft_read(-1, str_a, size);
		a_err = errno;
	
		errno = 0;
		b = ft_read(-1, str_b, size);
		b_err = errno;

		if (a != b || a_err != b_err)
		{
			flag = 0;
			break;
		}
	}
	close(fd_a);
	close(fd_b);
	remove(large_file_a);
	remove(large_file_b);
	test_result(flag);
}

void	test_strdup()
{
	int flag = 1;
	for (int i = 0; i < COUNT; ++i)
	{
		int size = rand() % COUNT;
		char str[size + 1];
		char *result_a;
		char *result_b;
		for (int j = 0; j < size; ++j)
			str[j] = rand() % 127 + 1;
		str[size] = '\0';
		result_a = ft_strdup(str);
		result_b = strdup(str);
		if (strcmp(result_a, result_b))
		{
			flag = 0;
			free(result_a);
			free(result_b);
			break ;
		}
		free(result_a);
		free(result_b);
	}
	test_result(flag);
}

int main()
{
	srand(time(NULL));
	printf("STRLEN\t");
	test_strlen();

	printf("STRCPY\t");
	test_strcpy();

	printf("STRCMP\t");
	test_strcmp();

	printf("WRITE\t");
	test_write();

	printf("READ\t");
	test_read();

	printf("STRDUP\t");
	test_strdup();

	return 0;
}
