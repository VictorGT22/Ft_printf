/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:03:21 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/17 10:34:13 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"
/*
int	external_x_write(t_list *info, unsigned int nbr, int width, int prec)
{
	int	total;

	total = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-")
		&& (!ft_is_inarr(info->flag, "0") || ft_is_inarr(info->flag, ".")))
		total += write_width(width);
	if (ft_is_inarr(info->flag, " ") && nbr >= 0 && (!width || !prec))
		total += write(1, " ", 1);
	if (ft_is_inarr(info->flag, "#") && nbr != 0)
		total += write(1, "0x", 2);
	if (prec > 0)
		total += put_c_num('0', prec);
	if (width > 0 && !ft_is_inarr(info->flag, ".")
		&& ft_is_inarr(info->flag, "0"))
		total += put_c_num('0', width + ft_is_inarr(info->flag, " "));
	if (nbr != 0 || !ft_is_inarr(info->flag, "."))
		ft_putnbr_base(nbr, "0123456789abcdef");
	if (width > 0 && ft_is_inarr(info->flag, "-")
		&& !ft_is_inarr(info->flag, "0"))
		total += write_width(width);
	return (total);
}

int	external_ux_write(t_list *info, unsigned int nbr, int width, int prec)
{
	int	total;

	total = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-")
		&& (!ft_is_inarr(info->flag, "0") || ft_is_inarr(info->flag, ".")))
		total += write_width(width);
	if (ft_is_inarr(info->flag, " ") && nbr >= 0 && (!width || !prec))
		total += write(1, " ", 1);
	if (ft_is_inarr(info->flag, "#") && nbr != 0)
		total += write(1, "0X", 2);
	if (prec > 0)
		total += put_c_num('0', prec);
	if (width > 0 && !ft_is_inarr(info->flag, ".")
		&& ft_is_inarr(info->flag, "0"))
		total += put_c_num('0', width + ft_is_inarr(info->flag, " "));
	if (nbr != 0 || !ft_is_inarr(info->flag, "."))
		ft_putnbr_base(nbr, "0123456789ABCDEF");
	if (width > 0 && ft_is_inarr(info->flag, "-")
		&& !ft_is_inarr(info->flag, "0"))
		total += write_width(width);
	return (total);
}
*/
int	func_x(va_list list, t_list *info)
{
	char *str;
	bool neg;
	int num;
	int len;

	neg = false;
	num = va_arg(list, int);
	str = ft_convert_base(num, "0123456789abcdef");
	str = add_precs(info, str, neg);
	str = add_width(info, str, neg);
	len = ft_myputstr(str, info);
	free(str);
	return (len);
}

int	func_upper_x(va_list list, t_list *info)
{
	char *str;
	bool neg;
	int num;
	int len;

	neg = false;
	num = va_arg(list, int);
	str = ft_convert_base(num, "0123456789ABCDEF");
	str = add_precs(info, str, neg);
	str = add_width(info, str, neg);
	len = ft_myputstr(str, info);
	free(str);
	return (len);
}
