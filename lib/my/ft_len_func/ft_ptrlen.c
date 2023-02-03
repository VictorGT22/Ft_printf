/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:39:54 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/03 03:59:04 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptrlen(uintptr_t num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (5);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}
