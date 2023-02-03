#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/include/ft_printf.h"

int main()
{
	int prova = 58;
	int i = ft_printf(" %.s\n", "-");
	int j = printf(" %.s\n", "-");
	printf("%d %d\n", i, j);
}