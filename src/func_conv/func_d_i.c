/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:48:07 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/03 06:14:22 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_d(va_list list, t_list *info)
{
	int len;
	long long int nbr;
	int width = 0;

	nbr = va_arg(list, int);
	len = ft_nbrlen((long long)nbr);
	width = atoi(info->width) - len - ft_is_inarr(info->flag, "+");
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-") && !ft_is_inarr(info->flag, "0"))
		write_width(width);
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	flag_sign(nbr, info);
	if (ft_is_inarr(info->flag, "0"))
		put_c_num('0', width);
	ft_putnbr_base(nbr, "0123456789");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (width + len + ft_is_inarr(info->flag, "+"));
}

int	func_D(va_list list, t_list *info)
{
	int len;
	long long int nbr;
	int width = 0;

	nbr = va_arg(list, int);
	len = ft_nbrlen((long long)nbr);
	width = atoi(info->width) - len - ft_is_inarr(info->flag, "+");
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-") && !ft_is_inarr(info->flag, "0"))
		write_width(width);
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	flag_sign(nbr, info);
	if (ft_is_inarr(info->flag, "0"))
		put_c_num('0', width);
	ft_putnbr_base(nbr, "0123456789");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (width + len + ft_is_inarr(info->flag, "+"));
}
