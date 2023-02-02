/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:30:53 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/02 09:24:20 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "libft.h"

s_Main *inti_structs()
{
	s_Main *var = malloc(sizeof(s_Main));
	var->flags = ft_split((const char *)"#, ,0,+,-,h,hh,l,ll,j,z,*,$,L,", ',');
	var->conv = ft_strdup("sSpdDioOuUxXcCeEfFgGaAnbrkp%");
	return (var);
}

int	ft_printf(const char *str, ...)
{
	s_Main *var;
	va_list list;
	int total;

	va_start(list, str);
	var = inti_structs();
	var->first_ptr = malloc(sizeof(t_list));
	var->current_ptr = var->first_ptr;
	var->num_conv = ft_strlen(var->conv);
	var->arr_func = malloc(sizeof(s_fnc_ptr) * (var->num_conv));
	fill_operations(var->arr_func);
	total = get_params(var, (char *)str, list);
	free_all(var);
	va_end(list);
	return (total);
}
