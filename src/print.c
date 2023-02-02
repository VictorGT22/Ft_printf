/*
** EPITECH PROJECT, 2021
** print example
** File description:
** example
*/

 #include "libft.h"
 #include "../include/ft_printf.h"
 #include <stdio.h>
 #include <limits.h>

 int main()
 {
    unsigned int x = 4294967295; 
    int i = ft_printf("hola esto%b es una prueba: %s %c\n", 2, "dfjhb", 's');
    int j = printf("hola esto%p es una prueba: %s %c\n", &x, "dfjhb", 's');

   return 0;
 }