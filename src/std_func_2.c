/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_func_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:19:54 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/22 08:50:48 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/ft_printf.h"

int	ft_myputstr(char *str, t_list *info)
{
	int	i;
	int error;
	int	len;

	i = 0;
	if (str == NULL)
		str = "(null)";
	if (ft_is_inarr(info->flag, ".") && info->conv == 's')
		len = atoi(info->precision);
	else
		len = ft_strlen(str);
	if (info->no_val_prec)
		len = 0;
	while (str[i] != '\0' && i < len)
	{
		error = write(1, &str[i], 1);
		if (error == -1)
			return (error);
		i++;
	}
	return (i);
}
