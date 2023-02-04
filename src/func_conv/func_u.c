/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:36:57 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/04 07:30:16 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_u(va_list list, t_list *info)
{
	int len;
	int total;
	unsigned int nbr;
	int width;

	total = 0;
	len = 0;
	nbr = va_arg(list, unsigned int);
	ft_len_nbr_base_u(nbr, "0123456789", &len);
	width = atoi(info->width) - len - ft_is_inarr(info->flag, " ");
	if (ft_is_inarr(info->flag, " "))
		write(1, " ", 1);
	if (ft_is_inarr(info->flag, ".") && !info->no_val_prec)
	{
		width += atoi(info->precision);
		width += nbr < 0 ? 1 : 0;
	}
	width = width < 0 ? 0 : width;
	if (width > 0 && !ft_is_inarr(info->flag, "-") && !ft_is_inarr(info->flag, "0") && !ft_is_inarr(info->flag, "0") && !ft_is_inarr(info->flag, "."))
		write_width(width);
	if (ft_is_inarr(info->flag, "0") || (ft_is_inarr(info->flag, ".") && !info->no_val_prec))
		put_c_num('0', width);
	ft_putnbr_base_l(nbr, "0123456789");
	if (width > 0 && ft_is_inarr(info->flag, "-") && !ft_is_inarr(info->flag, "0"))
		write_width(width);
	return (width + len + ft_is_inarr(info->flag, " "));
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