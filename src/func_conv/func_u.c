/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:36:57 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/22 08:51:28 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_u(va_list list, t_list *info)
{
	char *str;
	bool neg;
	unsigned int num;
	int len;

	neg = false;
	num = va_arg(list, int);
	str = ft_itoa(num);
	str = add_precs(info, str, neg);
	str = add_width(info, str, neg);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

