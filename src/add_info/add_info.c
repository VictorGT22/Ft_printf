/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:27:34 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/20 12:18:14 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

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
	c = get_width_char(info, str, neg);
	if (c == ' ')
		str = add_signs(info, str, neg);
	width = get_total_width(info, str, neg, c);
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
		str = ft_strdup(new);
		free(new);
		free(zero);
	}
	if (c == '0')
		str = add_signs(info, str, neg);
	return (str);
}
