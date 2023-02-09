/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:36:57 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/07 03:55:52 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_u(va_list list, t_list *info)
{
	int len;
	unsigned int nbr;
	int width = 0;
	int precision = 0;

	len = 0;
	nbr = va_arg(list, unsigned int);
	ft_len_nbr_base_u(nbr, "0123456789", &len);
	width = atoi(info->width) - ft_is_inarr(info->flag, " ");
	if (ft_is_inarr(info->flag, ".") && !info->no_val_prec)
	{
		precision = atoi(info->precision) - len;
		if(nbr < 0)
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

	if (width > 0 && !ft_is_inarr(info->flag, "-") && (!ft_is_inarr(info->flag, "0")
		|| ft_is_inarr(info->flag, ".")))
		write_width(width);
	if (ft_is_inarr(info->flag, " ") && !ft_is_inarr(info->flag, "0"))
		write(1, " ", 1);
	
	if (precision > 0)
		put_c_num('0', precision);
	if (width > 0 && !ft_is_inarr(info->flag, ".") && ft_is_inarr(info->flag, "0"))
		put_c_num('0', width + ft_is_inarr(info->flag, " "));
	ft_putnbr_base_l(nbr, "0123456789");

	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	width += ft_is_inarr(info->flag, " ");
	return (width + len + precision);
}

int	func_U(va_list list, t_list *info)
{
	int len;
	int total;
	unsigned long int nbr;
	int width;

	total = 0;
	len = 0;
	nbr = va_arg(list, unsigned long int);
	ft_len_nbr_base_u(nbr, "0123456789", &len);
	width = atoi(info->width) - len;
	width = width < 0 ? 0 : width;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	ft_putnbr_base_u(nbr, "0123456789");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (width + len);
}