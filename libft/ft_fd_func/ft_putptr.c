/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:25:51 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/17 10:52:09 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

void	ft_putptr(uintptr_t num, char *str, char *base)
{
	if (num >= 16)
	{
		ft_putptr(num / 16, str, base);
		ft_putptr(num % 16, str, base);
	}
	else
		ft_add_in_str(str, (base[num]));
}

char	*ft_getptr(uintptr_t num)
{
	char *str;
	int len;

	len = 0;
	ft_len_nbr_base_u(num, "0123456789abcdef", &len);
	str = malloc(sizeof(char) * len + 3);
	if (!str)
		return (NULL);
	str = ft_memset(str, '\0', len + 3);
	ft_putptr(num, str, "0123456789abcdef");
	return (str);
}
