/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:48:07 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/24 08:52:59 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_d(va_list list, t_list *info)
{
	char		*str;
	bool		neg;
	long int	num;
	int			len;

	neg = false;
	num = va_arg(list, int);
	if (num < 0)
	{
		neg = true;
		num = num * -1;
	}
	str = ft_convert_base(num, "0123456789");
	if (!str)
		return (-1);
	if (num == 0 && (atoi(info->precision) == 0 || info->no_val_prec))
		ft_bzero(str, strlen(str));
	if (!str)
		return (-1);
	str = add_precs(info, str, neg);
	str = add_width(info, str, neg);
	str = add_space(info, str, neg);
	len = ft_myputstr(str, info);
	free(str);
	return (len);
}
