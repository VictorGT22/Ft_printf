/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:16:03 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/16 19:54:28 by victgonz         ###   ########.fr       */
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
*/

	j = printf("\\!/%2.0d\\!/\n", 1);
	i = ft_printf("\\!/%2.0d\\!/\n", 1);
	ft_printf("%d %d\n\n", j, i);


	j = printf(">------------<% 5d>------------<\n", 10222);
	i = ft_printf(">------------<% 5d>------------<\n", 10222);
	ft_printf("%d %d\n\n", j, i);

	j = printf(">------------<% 6.2d>------------<\n", 2921);
	i = ft_printf(">------------<% 6.2d>------------<\n", 2921);
	ft_printf("%d %d\n\n", j, i);

	j = printf("42% 4.5d42\n", 10);
	i = ft_printf("42% 4.5d42\n", 10);
	//ft_printf("%d %d\n\n", j, i);

	j = printf("^.^/% 8.39d^.^\n", 905485281);
	i = ft_printf("^.^/% 8.39d^.^\n", 905485281);
	//printf("%d %d\n\n", j, i);

	j = printf("^.^/% 3d^.^/\n", 20);
	i = ft_printf("^.^/% 3d^.^/\n", 20);
	//ft_printf("%d %d\n\n", j, i);
	
	j = printf("% -7.2d!\n", 1);
	i = ft_printf("% -7.2d!\n", 1);
	//ft_printf("%d %d\n\n", j, i);
	j = printf("%-7i\n", 33);
	i = ft_printf("%-7i\n", 33);
	//ft_printf("%d %d\n\n", j, i);

	j = printf("% -48.30d/\n", -700370788);
	i = ft_printf("% -48.30d/\n", -700370788);
	//ft_printf("%d %d\n\n", j, i);

	j = printf("^.^/%-62.12d^.^/\n", -2100976222);
	i = ft_printf("^.^/%-62.12d^.^/\n", -2100976222);
	//ft_printf("%d %d\n\n", j, i);


	j = printf("^.^/% -3.3d^.^/\n", 0);
	i = ft_printf("^.^/% -3.3d^.^/\n", 0);
	//ft_printf("%d %d\n\n", j, i);

	j = printf("42% -22.48d42/\n", 1934456091);
	i = ft_printf("42% -22.48d42/\n", 1934456091);
	//ft_printf("%d %d\n\n", j, i);

	j = printf("^.^/% -16.16d^.^/\n", 0);
	i = ft_printf("^.^/% -16.16d^.^/\n", 0);
	//ft_printf("%d %d\n\n", j, i);
	j = printf("% -42.44d/\n", 477862486);
	i = ft_printf("% -42.44d/\n", 477862486);
	//ft_printf("%d %d\n\n", j, i);

	j = printf("% -42.44d/\n", -477862486);
	i = ft_printf("% -42.44d/\n", -477862486);
	//ft_printf("%d %d\n\n", j, i);
	j = printf("\\!/% -12.2d\\!/\n", -1694564368);
	i = ft_printf("\\!/% -12.2d\\!/\n", -1694564368);
	//ft_printf("%d %d\n\n", j, i);

	j = printf("\\!/% -11d\\!/\n", -1694564368);
	i = ft_printf("\\!/% -11d\\!/\n", -1694564368);
	//ft_printf("%d %d\n\n", j, i);


	j = printf("% -10.2d/\n", 238742731);
	i = ft_printf("% -10.2d/\n", 238742731);
	//ft_printf("%d %d\n\n", j, i);
	j = printf("% -2d/\n", 0);
	i = ft_printf("% -2d/\n", 0);

	j = printf("\\!/% -3.1d\\!/\n", -8);
	i = ft_printf("\\!/% -3.1d\\!/\n", -8);
//	ft_printf("%d %d\n\n", j, i);

	j = printf( "^.^/% 054d^.^/\n", 0);
	i = ft_printf( "^.^/% 054d^.^/\n", 0);
	//ft_printf("%d %d\n\n", j, i);


	j = printf("!% 05.2d!\n", 0);
	i = ft_printf("!% 05.2d!\n", 0);
	//ft_printf("%d %d\n\n", j, i);
	j = printf("!%04.2d!\n", -21);
	i = ft_printf("!%04.2d!\n", -21);
	j = printf("\\!/% -3.1d\\!/\n", -8);
	i = ft_printf("\\!/% -3.1d\\!/\n", -8);
//	ft_printf("%d %d\n\n", j, i);
	j = printf( "^.^/% 05d^.^/\n", 10);
	i = ft_printf( "^.^/% 05d^.^/\n", 10);

	i = printf("!% 48.45d!\n", -1614172260);
	j = ft_printf("!% 48.45d!\n", -1614172260);
	printf("%d %d\n", i, j);

	i = printf("\\!/% 4.2d\\!/\n", -680320706);
	j = ft_printf("\\!/% 4.2d\\!/\n", -680320706);
	printf("%d %d\n", i, j);

	i = printf(">------------<% 6.4d>------------<\n", -73);
	j = ft_printf(">------------<% 6.4d>------------<\n", -73);
	printf("%d %d\n", i, j);
}
