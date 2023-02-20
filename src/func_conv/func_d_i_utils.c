/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_d_i_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:48:07 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/20 11:13:36 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	write_ext_nums(t_list *info, long long int nbr, int width, int prec)
{
	int	total;

	total = 0;
	total += flag_sign(&nbr, info);
	if (prec > 0)
		total += put_c_num('0', prec);
	if (width > 0 && !ft_is_inarr(info->flag, ".")
		&& ft_is_inarr(info->flag, "0"))
		total += put_c_num('0', width);
	if (nbr != 0 || !ft_is_inarr(info->flag, "."))
		ft_putnbr_base(nbr, "0123456789");
	return (total);
}

bool	cond_first_space(t_list *info, long long int nbr1, int width, int prec)
{
	if (ft_is_inarr(info->flag, " ") && nbr1 >= 0
		&& !ft_is_inarr(info->flag, "+") || ((atoi(info->width) - 1)
			> atoi(info->precision) && !ft_is_inarr(info->flag, "-")
			&& (prec != 0 || atoi(info->width) > ft_nbrlen(nbr1)
				&& !width)) && !ft_is_inarr(info->flag, "+"))
		return (true);
	return (false);
}

bool	cond_second_space(t_list *info, long long int nbr1, bool space)
{
	if (ft_is_inarr(info->flag, " ") && nbr1 < 0
		&& atoi(info->width) > ft_nbrlen(nbr1) && !space)
		if ((atoi(info->width) - 1) > atoi(info->precision)
			&& ft_is_inarr(info->flag, ".") && !ft_is_inarr(info->flag, "0"))
			return (true);
	return (false);
}

bool	cond_third_space(t_list *info, long long int nbr1, bool space, int prec)
{
	if (ft_is_inarr(info->flag, " ") && nbr1 < 0
		&& atoi(info->width) > ft_nbrlen(nbr1) && !space)
		if (!ft_is_inarr(info->flag, ".") && !ft_is_inarr(info->flag, "0")
			&& prec == 0)
			return (true);
	return (false);
}

int	write_external_2(t_list *info, long long int nbr1, int width, bool *space)
{
	int	total;

	total = 0;
	if (width && ft_is_inarr(info->flag, "-"))
	{
		total += write_width(width);
		if (ft_is_inarr(info->flag, " ") && nbr1 < 0)
		{
			total += write(1, " ", 1);
			*space = true;
		}
	}
	if (cond_second_space(info, nbr1, *space))
		total += write(1, " ", 1);
	return (total);
}

int	write_external(t_list *info, long long int nbr, int width, int prec)
{
	int		nbr1;
	bool	space;
	int		total;

	nbr1 = nbr;
	total = 0;
	space = false;
	if (width && !ft_is_inarr(info->flag, "-")
		&& (!ft_is_inarr(info->flag, "0") || ft_is_inarr(info->flag, ".")))
	{
		total += write_width(width);
		if (ft_is_inarr(info->flag, " ") && (!ft_is_inarr(info->flag, "0")
				|| prec != 0 || nbr > 0))
		{
			total += write(1, " ", 1);
			space = true;
		}
	}
	else if (cond_first_space(info, nbr1, width, prec))
	{
		total += write(1, " ", 1);
		space = true;
	}
	total += write_ext_nums(info, nbr, width, prec);
	total += write_external_2(info, nbr1, width, &space);
	if (cond_third_space(info, nbr1, space, prec))
		total += write(1, " ", 1);
	return (total);
}
