/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:48:07 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/16 19:56:47 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	write_external(t_list *info, long long int nbr, int width, int prec)
{
	int	nbr1;
	bool space;
	int	total;

	nbr1 = nbr;
	total = 0;
	space = false;
	if (width && !ft_is_inarr(info->flag, "-")
		&& (!ft_is_inarr(info->flag, "0") || ft_is_inarr(info->flag, ".")))
	{
		total += write_width(width);
		if (ft_is_inarr(info->flag, " "))
		{
			total += write(1, " ", 1);
			space = true;
		}
	}
	else if (ft_is_inarr(info->flag, " ") && nbr1 >= 0 || ft_is_inarr(info->flag, " ") && prec != 0)
	{
		total += write(1, " ", 1);
		space = true;
	}
	total += flag_sign(&nbr, info);
	if (prec > 0)
		total += put_c_num('0', prec);
	if (width > 0 && !ft_is_inarr(info->flag, ".")
		&& ft_is_inarr(info->flag, "0"))
		total += put_c_num('0', width);
	if (nbr != 0 || !ft_is_inarr(info->flag, "."))
		ft_putnbr_base(nbr, "0123456789");
	if (width && ft_is_inarr(info->flag, "-"))
		total += write_width(width);
	if (ft_is_inarr(info->flag, " ") && nbr1 < 0
		&& atoi(info->width) > ft_nbrlen(nbr1) && !space && atoi(info->width) > atoi(info->precision))
		total += write(1, " ", 1);
	return (total);
}

int	get_d_width_prec(t_list *info, int nbr, int *add_width, int *len)
{
	int	precision;
	int	width;

	precision = 0;
	width = atoi(info->width);
	if ((width < *len))
		width--;
	if (nbr == 0 && ft_is_inarr(info->flag, "."))
		*len = 0;
	if (ft_is_inarr(info->flag, "+") && nbr >= 0)
		width -= 1;
	if (ft_is_inarr(info->flag, ".") && !info->no_val_prec)
	{
		precision = atoi(info->precision) - *len;
		if (nbr < 0)
			precision++;
	}
	if (precision <= 0)
	{
		width -= *len;
		width -= ft_is_inarr(info->flag, " ");
	}
	else
	{
		width -= (precision + *len);
		width -= ft_is_inarr(info->flag, " ");
	}
	if (width <= 0)
		width = 0;
	if (precision < 0)
		precision = 0;
	*add_width = width;
	return (precision);
}

int	func_d(va_list list, t_list *info)
{
	int				len;
	long long int	nbr;
	long long int	nbr1;
	int				width;
	int				precision;
	int				total;

	total = 0;
	nbr = va_arg(list, int);
	nbr1 = nbr;
	len = ft_nbrlen((long long)nbr);
	width = atoi(info->width);
	precision = get_d_width_prec(info, nbr, &width, &len);
	total = write_external(info, nbr, width, precision);
	printf("width: %d, precision: %d\n", width, precision);
	/*if (ft_is_inarr(info->flag, " ") && nbr1 >= 0 && (!width || !precision)
		&& (atoi(info->width) - precision) <= len)
		width++;
	else if (ft_is_inarr(info->flag, " ") && ft_is_inarr(info->flag, "-")
		&& atoi(info->width) > len && (atoi(info->width) >  atoi(info->precision)))
		width++;
	else if (ft_is_inarr(info->flag, " ") && ft_is_inarr(info->flag, "-")&& nbr >= 0)
		width++;*/
	if (nbr1 < 0)
		total--;
	return (total + len);
}

int	func_upper_d(va_list list, t_list *info)
{
	int				len;
	long long int	nbr;
	long long int	nbr1;
	int				width;
	int				precision;

	nbr = va_arg(list, int);
	nbr1 = nbr;
	len = ft_nbrlen((long long)nbr);
	width = atoi(info->width);
	precision = get_d_width_prec(info, nbr, &width, &len);
	
	printf("width: %d, precision: %d\n", width, precision);
	//write_external(info, nbr, width, precision);
	//printf("len : %d\n", len);
	/*if (ft_is_inarr(info->flag, " ") && nbr1 >= 0 && (!width || !precision)
		&& (atoi(info->width) - precision) <= len)
	{
		printf("entra\n");		
		width++;
	}
	if (ft_is_inarr(info->flag, " "))
	{
		printf("entra\n");		
		width++;
	}
	if (ft_is_inarr(info->flag, " ") && ft_is_inarr(info->flag, "-")
		&& nbr1 < 0 && (atoi(info->width) - len) > precision)
		width++;
	if (ft_is_inarr(info->flag, "+") && nbr1 >= 0)
		width++;
	*/
	return (width + len + precision);
}

/*void	write_external(t_list *info, long long int nbr, int width, int prec)
{
	int nbr1;

	nbr1 = nbr;
	if (width > 0 && !ft_is_inarr(info->flag, "-")
		&& (!ft_is_inarr(info->flag, "0") || ft_is_inarr(info->flag, ".")))
		write_width(width);
	if (ft_is_inarr(info->flag, " ") && nbr >= 0 && (!width || !prec)
		&& (atoi(info->width) - prec) <= ft_nbrlen((long long)nbr))
	{	
		write(1, " ", 1);
	}
	else if (ft_is_inarr(info->flag, " ") && ft_is_inarr(info->flag, "-")&& nbr >= 0)
	{
		write(1, " ", 1);
	}
	else if (ft_is_inarr(info->flag, " ") && ft_is_inarr(info->flag, "0") && nbr >= 0 && !ft_is_inarr(info->flag, "."))
	{
		width--;
		write(1, " ", 1);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	else
		flag_sign(nbr, info);
	if (prec > 0)
		put_c_num('0', prec);
	if (width > 0 && !ft_is_inarr(info->flag, ".")
		&& ft_is_inarr(info->flag, "0"))
		put_c_num('0', width);
	if (nbr != 0 || !ft_is_inarr(info->flag, "."))
		ft_putnbr_base(nbr, "0123456789");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	if (ft_is_inarr(info->flag, " ") && ft_is_inarr(info->flag, "-")
		&& nbr1 < 0)
	{
		write(1, " ", 1);
	}
	else if (ft_is_inarr(info->flag, " ") && ft_is_inarr(info->flag, "-")
		&& nbr1 < 0 && (atoi(info->width) - ft_nbrlen((long long)nbr)) >= atoi(info->precision))
		write(1, " ", 1);
	//printf("result; %d\n", atoi(info->width) - ft_nbrlen((long long)nbr));
}*/