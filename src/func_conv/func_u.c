/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:36:57 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/02 10:13:13 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_u(va_list list, t_list *info)
{
	int len;
	int total;
	unsigned long long int nbr;
	int width;

	total = 0;
	len = 0;
	nbr = va_arg(list, unsigned long int);
	ft_len_nbr_base(nbr, "0123456789", &len);
	width = atoi(info->width) - len;
	width = width < 0 ? 0 : width;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	ft_putnbr_base_u(nbr, "0123456789");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (width + len);
}

int	func_U(va_list list, t_list *info)
{
	int len;
	int total;
	unsigned long long int nbr;
	int width;

	total = 0;
	len = 0;
	nbr = va_arg(list, unsigned long int);
	ft_len_nbr_base(nbr, "0123456789", &len);
	width = atoi(info->width) - len;
	width = width < 0 ? 0 : width;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	ft_putnbr_base_u(nbr, "0123456789");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (width + len);
}