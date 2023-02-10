#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/include/ft_printf.h"

int main()
{
	int i = ft_printf("%24.6s\n", NULL);
	int j = printf("%24.6s\n", NULL);
	printf("%d %d\n", i, j);
}