/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_s_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:57:19 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/02 10:13:04 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_c(va_list list, t_list *info)
{
	char c;
	int width;

	c = va_arg(list, int);
	width = atoi(info->width) - 1;
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	write(1, &c, 1);
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (1 + width);
}

int	func_C(va_list list, t_list *info)
{
	char c;
	int width;

	c = va_arg(list, int);
	width = atoi(info->width) - 1;
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	write(1, &c, 1);
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (1 + width);
}

int	func_s(va_list list, t_list *info)
{
	char *s;
	int total;
	int width;

	s = va_arg(list, char *);
	width = atoi(info->width) - ft_strlen(s);
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	total = ft_myputstr(s);
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (total + width);
}

int	func_S(va_list list, t_list *info)
{
	char *s;
	int total;
	int width;

	s = va_arg(list, char *);
	width = atoi(info->width) - ft_strlen(s);
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	total = ft_myputstr(s);
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (total + width);
}