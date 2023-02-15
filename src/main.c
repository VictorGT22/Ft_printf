/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:16:03 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/15 17:47:05 by victgonz         ###   ########.fr       */
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
	j = printf("\\!/%2.0d\\!/\n", 1);
	i = ft_printf("\\!/%2.0d\\!/\n", 1);
	printf("%d %d\n", j, i);
	*/

	j = printf(">------------<% 41.32d>------------<\n", 0);
	i = ft_printf(">------------<% 41.32d>------------<\n", 0);
	printf("%d %d\n", j, i);
}
