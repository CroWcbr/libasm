#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#include "libasm.h"

#define COUNT	10000
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"

void	test_result(int result)
{
	if (result)
		printf(GREEN "OK" RESET "\n");
	else
		printf(RED "FAILED" RESET "\n");
}

int main()
{
	srand(time(NULL));
	printf("TTTT\t");


	return 0;
}