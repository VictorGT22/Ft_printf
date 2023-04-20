/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_info2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:28:56 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/20 11:57:26 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

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
}

char	get_width_char(t_list *info, char *str, int neg)
{
	int	c;

	if (ft_is_inarr(info->flag, "0") && !ft_is_inarr(info->flag, ".")
		&& !ft_is_inarr(info->flag, "-"))
		c = '0';
	else
		c = ' ';
	return (c);
}

int	get_total_width(t_list *info, char *str, int neg, int c)
{
	int	width;

	width = atoi(info->width) - ft_strlen(str);
	if (ft_is_inarr(info->flag, "+") && !neg && c == '0')
		width--;
	if (c == '0' && neg || ft_is_inarr(info->flag, " ") && !neg)
		width--;
	if (ft_is_inarr(info->flag, "#") && (info->conv == 'x'
			|| info->conv == 'X') && c == '0' && !ft_stronly_char(str, '0'))
		width -= 2;
	return (width);
}
