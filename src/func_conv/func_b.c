/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:34:32 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/24 08:52:17 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_b(va_list list, t_list *info)
{
	char			*str;
	unsigned int	num;
	int				len;

	num = va_arg(list, unsigned int);
	str = ft_convert_base(num, "01");
	if (!str)
		return (-1);
	str = add_precs(info, str, false);
	if (!str)
		return (-1);
	str = add_width(info, str, false);
	if (!str)
		return (-1);
	len = ft_myputstr(str, info);
	free(str);
	return (len);
}
