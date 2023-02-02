/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:03:21 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/02 15:22:57 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_x(va_list list, t_list *info)
{
	int len;
	int total;
	unsigned int nbr;
	int width;

	total = 0;
	len = 0;
	nbr = va_arg(list, unsigned int);
	ft_len_nbr_base(nbr, "0123456789abcdef", &len);
	width = atoi(info->width) - len;
	width -= ft_is_inarr(info->flag, "#") ? 2 : 0;
	width = width < 0 ? 0 : width;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	if (ft_is_inarr(info->flag, "#"))
		total += write(1, "0X", 2);
	ft_putnbr_base(nbr, "0123456789abcdef");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	width += ft_is_inarr(info->flag, "#") ? 2 : 0;
	return (width + len);
}

int	func_X(va_list list, t_list *info)
{
	int len;
	int total;
	unsigned int nbr;
	int width;

	total = 0;
	len = 0;
	nbr = va_arg(list, unsigned int);
	ft_len_nbr_base(nbr, "0123456789ABCDEF", &len);
	width = atoi(info->width) - len;
	width -= ft_is_inarr(info->flag, "#") ? 2 : 0;
	width = width < 0 ? 0 : width;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	if (ft_is_inarr(info->flag, "#"))
		total += write(1, "0X", 2);
	ft_putnbr_base(nbr, "0123456789ABCDEF");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	width += ft_is_inarr(info->flag, "#") ? 2 : 0;
	return (width + len);
}
