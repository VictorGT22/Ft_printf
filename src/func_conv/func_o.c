/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:58:06 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/20 11:23:35 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_o(va_list list, t_list *info)
{
	char	*str;
	bool	neg;
	int		num;
	int		len;

	neg = false;
	num = va_arg(list, int);
	str = ft_convert_base(num, "01234567");
	str = add_precs(info, str, neg);
	str = add_width(info, str, neg);
	len = ft_myputstr(str, info);
	free(str);
	return (len);
}
