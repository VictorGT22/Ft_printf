/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:16:56 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/17 10:59:19 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_p(va_list list, t_list *info)
{
	int len;
	char *str;
	uintptr_t num;

	len = 0;
	num = va_arg(list, unsigned long);
	str = ft_getptr(num);
	str = add_precs(info, str, false);
	str = add_width(info, str, false);
	len = ft_myputstr(str, info);
	free(str);
	return (len);
}
