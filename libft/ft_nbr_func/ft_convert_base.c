/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:54:03 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/17 11:36:34 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

static void	ext_convert_base(long long int nbr, char *str, char *base)
{
	if (nbr < 0)
	{
		nbr *= -1;
		ft_add_in_str(str, '-');
	}
	if (nbr >= ft_strlen(base))
	{
		ext_convert_base(nbr / ft_strlen(base), str, base);
		ext_convert_base(nbr % ft_strlen(base), str, base);
	}
	else
		ft_add_in_str(str, base[nbr]);
}

char	*ft_convert_base(long long int n, char *base)
{
	char		*str;
	long int	nbr;
	int			len;

	nbr = (long int)n;
	len = 0;
	ft_len_nbr_base(nbr, base, &len);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_memset(str, '\0', len + 1);
	ext_convert_base(nbr, str, base);
	return (str);
}


