/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:48:07 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/09 10:37:06 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int func_d(va_list list, t_list *info)
{
	int len;
	long long int nbr;
	long long int nbr1;
	int width = 0;
	int precision = 0;

	nbr = va_arg(list, int);
	nbr1 = nbr;
	len = ft_nbrlen((long long)nbr);
	width = atoi(info->width);
	if (nbr == 0 && ft_is_inarr(info->flag, "."))
		len = 0;
	if (ft_is_inarr(info->flag, "+") && nbr >= 0)
		width -= 1;
	if (ft_is_inarr(info->flag, ".") && !info->no_val_prec)
	{
		precision = atoi(info->precision) - len;
		if (nbr < 0)
			precision++;
	}
	if (precision <= 0)
		width -= len;
	else
		width -= (precision + len);
	if (width < 0)
		width = 0;
	if (precision < 0)
		precision = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-") && (!ft_is_inarr(info->flag, "0") || ft_is_inarr(info->flag, ".")))
		write_width(width);
	if (ft_is_inarr(info->flag, " ") && nbr >= 0 && (!width || !precision))
		write(1, " ", 1);
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	else
		flag_sign(nbr, info);
	if (precision > 0)
		put_c_num('0', precision);
	if (width > 0 && !ft_is_inarr(info->flag, ".") && ft_is_inarr(info->flag, "0"))
		put_c_num('0', width + ft_is_inarr(info->flag, " "));
	if (nbr != 0 || !ft_is_inarr(info->flag, "."))
		ft_putnbr_base(nbr, "0123456789");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	if (ft_is_inarr(info->flag, " ") && nbr >= 0 && (!width || !precision))
		width += ft_is_inarr(info->flag, " ") && nbr1 >= 0 ? 1 : 0;
	width += ft_is_inarr(info->flag, "+") && nbr1 >= 0 ? 1 : 0;
	return (width + len + precision);
}

int func_D(va_list list, t_list *info)
{
	int len;
	long long int nbr;
	long long int nbr1;
	int width = 0;
	int precision;

	precision = 0;
	nbr = va_arg(list, int);
	nbr1 = nbr;
	len = ft_nbrlen((long long)nbr);
	width = atoi(info->width) - len - ft_is_inarr(info->flag, "+") - ft_is_inarr(info->flag, " ");
	width -= ft_is_inarr(info->flag, "+") && nbr1 >= 0 ? 1 : 0;
	if (ft_is_inarr(info->flag, ".") && !info->no_val_prec)
	{
		if (atoi(info->precision) < len)
			precision = 0;
		else
		{
			precision = atoi(info->precision) - len;
			precision += nbr < 0 ? 1 : 0;
			width -= precision;
		}
	}
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-") && (!ft_is_inarr(info->flag, "0") || ft_is_inarr(info->flag, ".")))
		write_width(width);
	if (ft_is_inarr(info->flag, " ") && nbr >= 0)
		write(1, " ", 1);
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	else
		flag_sign(nbr, info);
	if (ft_is_inarr(info->flag, "0") || (ft_is_inarr(info->flag, ".") && !info->no_val_prec))
	{
		if (ft_is_inarr(info->flag, "0") && !ft_is_inarr(info->flag, "."))
			put_c_num('0', width);
		else
			put_c_num('0', precision);
	}
	if (nbr != 0)
		ft_putnbr_base(nbr, "0123456789");

	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	width += ft_is_inarr(info->flag, " ") && nbr1 >= 0 ? 1 : 0;
	width += ft_is_inarr(info->flag, "+") && nbr1 >= 0 ? 1 : 0;

	return (width + len + precision);
}
