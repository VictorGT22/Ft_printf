/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:16:03 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/17 09:56:07 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/include/ft_printf.h"

int main()
{
	int valor = 34;
	char *str = "%p %p %p\n";
	int j = ft_printf(str, LONG_MAX, LONG_MAX, LONG_MAX);
	int i = printf(str, LONG_MAX, LONG_MAX, LONG_MAX);
	//printf("mio: %d, suyo: %d\n\n\n", j, i);
}
