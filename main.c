#include <stdio.h>
#include "libasm.h"

void	test_strlen(const char *tmp)
{
	printf("%ld\t%s\n", ft_strlen(tmp), tmp);
}

int main()
{
	test_strlen("asdasda");
}
