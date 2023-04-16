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
	int valor = 34;
	char *msg = "hola como estas";
	char *str = "%b\n";
	int j = ft_printf(str, valor);
	//int i = printf(str, msg);
	//printf("mio: %d, suyo: %d\n\n\n", j, i);

}
