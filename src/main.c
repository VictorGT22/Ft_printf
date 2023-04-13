/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:16:03 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/13 13:12:53 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/include/ft_printf.h"

int main()
{
	char valor = -14;
	char *str = "%04d\n";
	int j = ft_printf(str, valor);
	int i = printf(str, valor);
	printf("mio: %d, suyo: %d", j, i);
	/*
	printf(" %c %c %c\n", '0', 0, '1');
	ft_printf(" %c %c %c\n", '0', 0, '1');
	*/
}
