#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/include/ft_printf.h"

int main()
{
	//ft_printf("%23s\n", NULL);
	//printf("%23s\n", NULL);

	int i = ft_printf("%5.1i\n", 1);
	int j = printf("%5.2i\n", 12);

	printf("%d %d\n", i, j);

/*
	int i = ft_printf("%3.s\n", (char *)NULL);
	int j = printf("%3.s\n",  (char *)NULL);

	printf("%d %d\n", i, j);
	ft_printf("%7.5s\n", "bombastic");
	ft_printf("%-7.5s\n", "yolo");
	ft_printf("%-7.5s\n", "tubular");
	ft_printf("%7.7s%7.7s\n", "hello", "world");
	ft_printf("%3.7s%7.7s\n", "hello", "world");
	ft_printf("%7.7s%3.7s\n", "hello", "world");
	ft_printf("%3.7s%3.7s\n", "hello", "world");
	ft_printf("%7.3s%7.7s\n", "hello", "world");
	ft_printf("%3.3s%7.7s\n", "hello", "world");
	ft_printf("%7.3s%3.7s\n", "hello", "world");
*/

}