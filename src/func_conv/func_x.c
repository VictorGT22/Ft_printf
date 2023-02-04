/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:03:21 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/04 04:05:34 by victgonz         ###   ########.fr       */
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
	width -= ft_is_inarr(info->flag, "#") && nbr != 0 ? 2 : 0;
	if (ft_is_inarr(info->flag, ".") && !info->no_val_prec)
	{
		width += atoi(info->precision);
		width += nbr < 0 ? 1 : 0;
	}
	width = width < 0 ? 0 : width;
	if (width > 0 && !ft_is_inarr(info->flag, "-") && !ft_is_inarr(info->flag, "0") && !ft_is_inarr(info->flag, "."))
		write_width(width);
	if (ft_is_inarr(info->flag, "#") && nbr != 0)
		total += write(1, "0x", 2);
	if (ft_is_inarr(info->flag, "0") || (ft_is_inarr(info->flag, ".") && !info->no_val_prec))
		put_c_num('0', width);
	ft_putnbr_base(nbr, "0123456789abcdef");
	if (width > 0 && ft_is_inarr(info->flag, "-") && !ft_is_inarr(info->flag, "0"))
		write_width(width);
	width += ft_is_inarr(info->flag, "#") && nbr != 0 ? 2 : 0;
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
	width -= ft_is_inarr(info->flag, "#") && nbr != 0 ? 2 : 0;
	if (ft_is_inarr(info->flag, ".") && !info->no_val_prec)
	{
		width += atoi(info->precision);
		width += nbr < 0 ? 1 : 0;
	}
	width = width < 0 ? 0 : width;
	if (width > 0 && !ft_is_inarr(info->flag, "-") && !ft_is_inarr(info->flag, "0") && !ft_is_inarr(info->flag, "."))
		write_width(width);
	if (ft_is_inarr(info->flag, "#") && nbr != 0)
		total += write(1, "0X", 2);
	if (ft_is_inarr(info->flag, "0") || (ft_is_inarr(info->flag, ".") && !info->no_val_prec))
		put_c_num('0', width);
	ft_putnbr_base(nbr, "0123456789ABCDEF");
	if (width > 0 && ft_is_inarr(info->flag, "-") && !ft_is_inarr(info->flag, "0"))
		write_width(width);
	width += ft_is_inarr(info->flag, "#") && nbr != 0 ? 2 : 0;
	return (width + len);
}
