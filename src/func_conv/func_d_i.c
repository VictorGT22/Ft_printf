/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:48:07 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/13 13:23:03 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

char	*add_signs(t_list *info, char *str, int neg)
{
	char *new; //= str;

	if (neg == true)
	{
		new = ft_strjoin("-", str);
		free(str);
		return (new);
	}
	if (ft_is_inarr(info->flag, "+"))
	{
		new = ft_strjoin("+", str);
		free(str);
		return (new);
	}
	return (str);
}

char *add_width(t_list *info, char *str, int neg)
{
	char	*new;
	int		width;
	char	c;
	char	*zero;

	zero = NULL;
	c = ' ';
	if (ft_is_inarr(info->flag, "0") && !ft_is_inarr(info->flag, "."))
		c = '0';
	width = atoi(info->width) - ft_strlen(str) - neg;
	if (width > 0)
	{
		zero = malloc(sizeof(char) * width + 1);
		zero = ft_memset(zero, c, width);
		zero[width] = '\0';
		if (ft_is_inarr(info->flag, "-"))
			new = ft_strjoin(str, zero);
		else
			new = ft_strjoin(zero, str);
		free(str);
		free(zero);
		return (new);
	}
	return (str);
}

char *add_precs(t_list *info, char *str, int neg)
{
	char	*new;
	int		precs;
	char	*zero;

	zero = NULL;
	precs = atoi(info->precision) - ft_strlen(str) - neg;
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

int	func_d(va_list list, t_list *info)
{
	char *str;
	bool neg;
	int num;
	int len;

	neg = false;
	num = va_arg(list, int);
	if (num < 0)
	{
		neg = true;
		num = num * -1;
	}
	printf("numero: %d\n", num);
	str = ft_itoa(num);
	printf("str: %s\n", str);
	printf("str2: %s\n", str);
	str = add_precs(info, str, neg);
	str = add_width(info, str, neg);
	str = add_signs(info, str, neg);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
