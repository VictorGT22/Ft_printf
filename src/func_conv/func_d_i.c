/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:48:07 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/20 11:41:22 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

/*
char	*add_prefix(t_list *info, char *str)
{
	char	*new;

	if (ft_is_inarr(info->flag, "#")
		&& !ft_stronly_char(str, '0') || info->conv == 'p')
	{
		if (info->conv == 'o' || info->conv == 'O')
			new = ft_strjoin("0", str);
		if (info->conv == 'e' || info->conv == 'p' || info->conv == 'x')
			new = ft_strjoin("0x", str);
		else
			new = ft_strjoin("0X", str);
		free(str);
		return (new);
	}
	return (str);
}

char	*add_signs(t_list *info, char *str, int neg)
{
	char	*new;

	str = add_prefix(info, str);
	if (neg == true && !ft_strchr(str, '-'))
	{
		new = ft_strjoin("-", str);
		free(str);
		return (new);
	}
	if (ft_is_inarr(info->flag, "+") && !neg)
	{
		new = ft_strjoin("+", str);
		free(str);
		return (new);
	}
	return (str);
}

char	*add_precs(t_list *info, char *str, int neg)
{
	char	*new;
	int		precs;
	char	*zero;

	zero = NULL;
	precs = atoi(info->precision) - ft_strlen(str);
	if (ft_is_inarr(info->flag, ".") && !info->no_val_prec && precs > 0)
	{
		zero = malloc(sizeof(char) * precs + 1);
		zero = ft_memset(zero, '0', precs);
		zero[precs] = '\0';
		new = ft_strjoin(zero, str);
		free(str);
		free(zero);
		return (new);
	}
	return (str);
}

char	*add_width(t_list *info, char *str, int neg)
{
	char	*new;
	int		width;
	char	c;
	char	*zero;

	zero = NULL;
	/////////
	if (ft_is_inarr(info->flag, "0") && !ft_is_inarr(info->flag, ".")
		&& !ft_is_inarr(info->flag, "-"))
		c = '0';
	else
	{
		c = ' ';
		str = add_signs(info, str, neg);
	}
	///////
	width = atoi(info->width) - ft_strlen(str); //ft_is_inarr(info->flag, "+") - neg
	if (ft_is_inarr(info->flag, "+") && !neg && c == '0')
		width--;
	if (c == '0' && neg	|| ft_is_inarr(info->flag, " ") && !neg)
		width--;
	if (ft_is_inarr(info->flag, "#") && (info->conv == 'x' ||
		info->conv == 'X') && c == '0' && !ft_stronly_char(str, '0'))
		width -= 2;
	//////	
	if (width > 0)
	{
		zero = malloc(sizeof(char) * width + 1);
		zero = ft_memset(zero, c, width);
		zero[width] = '\0';
		if (ft_is_inarr(info->flag, "-"))
			new = ft_strjoin(str, zero);
		else
			new = ft_strjoin(zero, str);
		if (c == '0')
			new = add_signs(info, new, neg);
		free(str);
		free(zero);
		return (new);
	}
	if (c == '0')
		str = add_signs(info, str, neg);
	return (str);
}

char	*add_space(t_list *info, char *str, int neg)
{
	char	*new;

	if (ft_is_inarr(info->flag, " ") && !neg)
	{
		new = ft_strjoin(" ", str);
		free(str);
		str = ft_strdup(new);
		free(new);
	}
	return (str);
}*/

int	func_d(va_list list, t_list *info)
{
	char		*str;
	bool		neg;
	long int	num;
	int			len;

	neg = false;
	num = va_arg(list, int);
	if (num < 0)
	{
		neg = true;
		num = num * -1;
	}
	str = ft_convert_base(num, "0123456789");
	if (!str)
		return (-1);
	if (num == 0 && (atoi(info->precision) == 0 || info->no_val_prec))
		ft_bzero(str, strlen(str));
	str = add_precs(info, str, neg);
	str = add_width(info, str, neg);
	str = add_space(info, str, neg);
	len = ft_myputstr(str, info);
	free(str);
	return (len);
}
