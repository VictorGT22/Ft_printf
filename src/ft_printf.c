/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:30:53 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/24 09:10:34 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/ft_printf.h"

t_Main	*inti_structs(void)
{
	t_Main	*var;

	var = ft_calloc(sizeof(t_Main), 1);
	if (!var)
		return (NULL);
	var->flags = ft_split((const char *)"#, ,0,+,-,h,hh,l,ll,j,z,*,$,L,", ',');
	var->conv = ft_strdup("sSpdDioOuUxXcCeEfFgGaAnbrp%");
	if (!var->flags || !var->conv)
		return (NULL);
	return (var);
}

int	ft_printf(const char *str, ...)
{
	t_Main	*var;
	va_list	list;
	int		total;

	va_start(list, str);
	var = inti_structs();
	if (!var)
	{
		va_end(list);	
		return (-1);
	}
	var->first_ptr = ft_calloc(sizeof(t_list), 1);
	var->current_ptr = var->first_ptr;
	var->num_conv = ft_strlen(var->conv);
	var->arr_func = ft_calloc(sizeof(t_fnc_ptr), (var->num_conv));
	if (!var->first_ptr || !var->arr_func)
	{
		free_all(var);
		return (-1);
	}
	fill_operations(var->arr_func);
	total = get_params(var, (char *)str, list);
	free_all(var);
	va_end(list);
	return (total);
}
