/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:36:57 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/24 08:48:26 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_u(va_list list, t_list *info)
{
	char			*str;
	bool			neg;
	unsigned int	num;
	int				len;

	neg = false;
	num = va_arg(list, unsigned int);
	str = ft_utoa(num);
	if (!str)
		return (-1);
	if (num == 0 && (atoi(info->precision) == 0 || info->no_val_prec))
		ft_bzero(str, strlen(str));
	str = add_precs(info, str, neg);
	str = add_width(info, str, neg);
	len = ft_myputstr(str, info);
	free(str);
	return (len);
}
