#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/include/ft_printf.h"

int main()
{
	int prova = 58;
	int i = ft_printf(" %-01s %-02s ", "", "-");
	int j = printf(" %-01s %-02s ", "", "-");
	printf("%d %d\n", i, j);
}