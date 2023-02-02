/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:05:42 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/02 10:39:41 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	flag_sign(int nbr, t_list *info)
{
	if (ft_is_inarr(info->flag, "+") && nbr >= 0)
	{
		write (1, "+", 1);
		return (1);
	}
	return (0);
}

void	write_width(int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		write(1, " ", 1);
		i++;
	}
}

int	print_decimal_part(long num, double decimal, t_list *info, char *base)
{
	int	prec;
	int i;
	int len_base;

	i = 0;
	len_base = ft_strlen(base);
	ft_putnbr_base_l(num, base);
	if (strlen(info->precision) > 0)
		prec = atoi(info->precision);
	else
		prec = 6;
	if (prec > 0)
		write(1, ".", 1);
	while (0 < prec)
	{
		decimal *= 10;
		if (decimal < 0)
			decimal *= -1;
        ft_putnbr_base((int)decimal % len_base, base);
		prec--;
	}
}

int	func_module(va_list list, t_list *info)
{
	(void)info;
	(void)list;
	write(1, "%", 1);
	return (1);
}

int	get_exponent(double *num)
{
	int count;

	count = 0;
	if (*num < 0)
	{
		*num *= -1;
		write(1, "-", 1);
	}
	while (*num / 10 >= 1.0)
	{
		count++;
		*num /= 10;
	}
	while (*num < 1.0)
	{
		count--;
		*num *= 10;
	}
	return (count);
}

void	write_exp(int exp)
{
	if (exp < 0)
	{
		write(1, "-", 1);
		exp *= -1;
	}
	else
		write(1, "+", 1);
	if (exp > -10 && exp < 10)
		write(1, "0", 1);
	ft_putnbr_base(exp, "0123456789");	
}

int	func_a(va_list list, t_list *info)
{
	double num;
	long unit_part;
	double deci_part;

	num = va_arg(list, double);
	unit_part = num;
	deci_part = num - unit_part;
	print_decimal_part(unit_part, deci_part, info, "0123456789abcdef");
}

int	func_A(va_list list, t_list *info)
{
	double num;
	int unit_part;
	double deci_part;

	num = va_arg(list, double);
	unit_part = num;
	deci_part = num - unit_part;
	print_decimal_part(unit_part, deci_part, info, "0123456789abcdef");
}

int	func_r(va_list list, t_list *info)
{
	printf("func_r\n");
	(void)info;
	(void)list;
	//ft_putstr(va_arg(list, int *));
}

int	func_k(va_list list, t_list *info)
{
	printf("func_k\n");
	(void)info;
	//ft_putstr(va_arg(list, char *));
}
