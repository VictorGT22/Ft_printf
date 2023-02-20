/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:16:03 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/20 09:00:47 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/include/ft_printf.h"

int	main(void)
{
	int	i;
	int	j;
	
	/*

	j = printf("\\!/%2.0u\\!/\n", 1);
	i = ft_printf("\\!/%2.0u\\!/\n", 1);
	ft_printf("%u %u\n\n", j, i);


	j = printf(">------------<% 5u>------------<\n", 10222);
	i = ft_printf(">------------<% 5u>------------<\n", 10222);
	ft_printf("%u %u\n\n", j, i);

	j = printf(">------------<% 6.2u>------------<\n", 2921);
	i = ft_printf(">------------<% 6.2u>------------<\n", 2921);
	ft_printf("%u %u\n\n", j, i);

	j = printf("42% 4.5u42\n", 10);
	i = ft_printf("42% 4.5u42\n", 10);
	ft_printf("%u %u\n\n", j, i);

	j = printf("^.^/% 8.39u^.^\n", 905485281);
	i = ft_printf("^.^/% 8.39u^.^\n", 905485281);
	printf("%u %u\n\n", j, i);

	j = printf("^.^/% 3u^.^/\n", 20);
	i = ft_printf("^.^/% 3u^.^/\n", 20);
	ft_printf("%u %u\n\n", j, i);
	
	j = printf("% -7.2u!\n", 1);
	i = ft_printf("% -7.2u!\n", 1);
	ft_printf("%u %u\n\n", j, i);
	j = printf("%-7i\n", 33);
	i = ft_printf("%-7i\n", 33);
	ft_printf("%u %u\n\n", j, i);

	j = printf("% -48.30u/\n", -700370788);
	i = ft_printf("% -48.30u/\n", -700370788);
	ft_printf("%u %u\n\n", j, i);

	j = printf("^.^/%-62.12u^.^/\n", -2100976222);
	i = ft_printf("^.^/%-62.12u^.^/\n", -2100976222);
	//ft_printf("%u %u\n\n", j, i);


	j = printf("^.^/% -3.3u^.^/\n", 0);
	i = ft_printf("^.^/% -3.3u^.^/\n", 0);
	ft_printf("%u %u\n\n", j, i);

	j = printf("42% -22.48u42/\n", 1934456091);
	i = ft_printf("42% -22.48u42/\n", 1934456091);
	ft_printf("%u %u\n\n", j, i);

	j = printf("^.^/% -16.16u^.^/\n", 0);
	i = ft_printf("^.^/% -16.16u^.^/\n", 0);
	ft_printf("%u %u\n\n", j, i);
	j = printf("% -42.44u/\n", 477862486);
	i = ft_printf("% -42.44u/\n", 477862486);
	ft_printf("%u %u\n\n", j, i);

	j = printf("% -44.42u/\n", -477862486);
	i = ft_printf("% -44.42u/\n", -477862486);
	ft_printf("%u %u\n\n", j, i);
	j = printf("\\!/% -12.2u\\!/\n", -1694564368);
	i = ft_printf("\\!/% -12.2u\\!/\n", -1694564368);
	ft_printf("%u %u\n\n", j, i);

	j = printf("\\!/% -11u\\!/\n", -1694564368);
	i = ft_printf("\\!/% -11u\\!/\n", -1694564368);
	ft_printf("%u %u\n\n", j, i);


	j = printf("% -10.2u/\n", 238742731);
	i = ft_printf("% -10.2u/\n", 238742731);
	ft_printf("%u %u\n\n", j, i);
	j = printf("% -2u/\n", 0);
	i = ft_printf("% -2u/\n", 0);

	j = printf("\\!/% -3.1u\\!/\n", -8);
	i = ft_printf("\\!/% -3.1u\\!/\n", -8);
	ft_printf("%u %u\n\n", j, i);

	j = printf( "^.^/% 054u^.^/\n", 0);
	i = ft_printf( "^.^/% 054u^.^/\n", 0);
	ft_printf("%u %u\n\n", j, i);


	j = printf("!% 05.2u!\n", 0);
	i = ft_printf("!% 05.2u!\n", 0);
	ft_printf("%u %u\n\n", j, i);
	j = printf("!%04.2u!\n", -21);
	i = ft_printf("!%04.2u!\n", -21);
	j = printf("\\!/% -3.1u\\!/\n", -8);
	i = ft_printf("\\!/% -3.1u\\!/\n", -8);
	ft_printf("%u %u\n\n", j, i);
	j = printf( "^.^/% 05u^.^/\n", 10);
	i = ft_printf( "^.^/% 05u^.^/\n", 10);

	i = printf("!% 48.45u!\n", -1614172260);
	j = ft_printf("!% 48.45u!\n", -1614172260);
	printf("%u %u\n", i, j);


	i = printf(">------------<% 6.4u>------------<\n", -73);
	j = ft_printf(">------------<% 6.4u>------------<\n", -73);
	printf("%u %u\n", i, j);

	i = printf("\\!/% 50.52u\\!/\n", -383961643);
	j = ft_printf("\\!/% 50.52u\\!/\n", -383961643);
	printf("%u %u\n", i, j);

	j = printf("% -44.42u/\n", -477862486);
	i = ft_printf("% -44.42u/\n", -477862486);
	
	i = printf("42% 020u42\n", -1233445358);
	j = ft_printf("42%0 20u42\n", -1233445358);
	printf("%u %u\n", i, j);


	i = printf("\\!/% -16u\\!/\n", -1797079540);
	j = ft_printf("\\!/% -16u\\!/\n", -1797079540);
	printf("%u %u\n", i, j);

	i = printf("42% 013.2u42\n", -1360524004);
	j = ft_printf("42% 013.2u42\n", -1360524004);
	printf("%u %u\n", i, j);

	j = printf( "% 012.1u!\n", -1280987380);
	i = ft_printf( "% 012.1u!\n", -1280987380);
	printf("%u %u\n", i, j);

	j = printf("!% 12.6u!\n", -2147483645);
	i = ft_printf("!% 12.6u!\n", -2147483645);
	printf("%u %u\n", i, j);
	
	i = printf("\\!/% 4.2u\\!/\n", -680320706);
	j = ft_printf("\\!/% 4.2u\\!/\n", -680320706);
	printf("%u %u\n", i, j);

	i = printf("42% -12u42/\n", -1326595320);
	j = ft_printf("42% -12u42/\n", -1326595320);
	printf("%u %u\n", i, j);

	i = printf("42% -19.18u42\n", -1616069102);
	j = ft_printf("42% -19.18u42\n", -1616069102);
	printf("%u %u\n", i, j);

	j = printf("\\!/% -3.1u\\!/\n", -8);
	i = ft_printf("\\!/% -3.1u\\!/\n", -8);
	ft_printf("%u %u\n\n", j, i);

	j = printf("!% 32.31u!/\n", -653993666);
	i = ft_printf("!% 32.31u!/\n", -653993666);
	ft_printf("%u %u\n\n", j, i);

// flag +
	i = printf("\\!/%0+11.2u\\!/\n", 1621096918);
	j = ft_printf("\\!/%0+11.2u\\!/\n", 1621096918);
	printf("%u %u\n", i, j);*/

/*
	i = printf(">------------<%#48.42X>------------<\n", -1817769312);
	j = ft_printf(">------------<%#48.42X>------------<\n", -1817769312);
	printf("%u %u\n", i, j);

	i = printf("42%#16.2X42\n", 0);
	j = ft_printf("42%#16.2X42\n", 0);
	printf("%u %u\n", i, j);
*/

	i = printf("%-+5.d, %-+5.d, %-+5.d, %-+5.d, %-+5.d, %-+5.d, %-+5.d, %-+5.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	j = ft_printf("%-+5.d, %-+5.d, %-+5.d, %-+5.d, %-+5.d, %-+5.d, %-+5.d, %-+5.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf("%d %d\n", i, j);

	/*i = printf("%0 5.i, %0 5.i, %0 5.i, %0 5.i, %0 5.i, %0 5.i, %0 5.i, %0 5.i\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	j = ft_printf("%0 5.i, %0 5.i, %0 5.i, %0 5.i, %0 5.i, %0 5.i, %0 5.i, %0 5.i\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf("%u %u\n", i, j);

	i = printf("%05.i/\n", 0);
	j = ft_printf("%05.i/\n", 0);
	printf("%u %u\n", i, j);*/
}

