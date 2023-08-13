#include <stdio.h>
#include <string.h>
#include "libasm.h"

void	test_strlen(const char *tmp)
{
	printf("input:\n\ttmp\t|%s|\nresult:\n", tmp);

	printf("\tft\t%ld\n", ft_strlen(tmp));

	printf("\tst\t%ld\n", strlen(tmp));

	printf("\n");
}

void	test_strcpy(const char *tmp)
{
	printf("input:\n\ttmp\t|%s|\nresult:\n", tmp);

	char	ft_cpy[ft_strlen(tmp) + 1];
	char	*ft_test = ft_strcpy(ft_cpy, tmp);
	printf("\tft\t%ld\t|%s|\n", ft_strlen(ft_test), ft_test);
	printf("\tft\t%ld\t|%s|\n", ft_strlen(ft_cpy), ft_cpy);

	char	cpy[strlen(tmp) + 1];
	char	*test = strcpy(cpy, tmp);
	printf("\tst\t%ld\t|%s|\n", strlen(test), test);
	printf("\tst\t%ld\t|%s|\n", strlen(cpy), cpy);

	printf("\n");
}

void	test_strcmp(const char *s1, const char *s2)
{
	printf("input:\n\ts1\t|%s|\n\ts2\t|%s|\nresult:\n", s1, s2);

	printf("\tft\t%d\n", ft_strcmp(s1,s2));

	printf("\tst\t%d\n", strcmp(s1,s2));

	printf("\n");
}

void	test_write(const char *s1)
{
	int len = ft_write(1, s1, ft_strlen(s1));
	printf("\n%d\n", len);
}

int main()
{
	printf("===============STRLEN===============\n");
	test_strlen("");
	test_strlen("asdasda");
	test_strlen("				dsfs");

	printf("===============STRCPY===============\n");
	test_strcpy("");
	test_strcpy("asdasda");
	test_strcpy("				dsfs");

	printf("===============STRCPY===============\n");
	test_strcmp("", "");
	test_strcmp("", "1");
	test_strcmp("1", "");
	test_strcmp("123", "123");
	test_strcmp("321", "123");
	test_strcmp("123", "321");

	printf("===============WRITE===============\n");
	test_write("qwerty");

	printf("====================================\n");
	return 0;
}
