/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:09:12 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/15 09:13:04 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_nbrlen(long long int nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_unbrlen(unsigned long int nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	ft_len_nbr_base(long long int nb, char *base, int *len)
{
	if (nb >= (long long)ft_strlen(base))
	{
		ft_len_nbr_base(nb / (long long)ft_strlen(base), base, len);
		ft_len_nbr_base(nb % (long long)ft_strlen(base), base, len);
	}
	if (nb < (long long)ft_strlen(base))
		*len += 1;
}

void	ft_len_nbr_base_u(unsigned long int nb, char *base, int *len)
{
	if (nb >= (unsigned long)ft_strlen(base))
	{
		ft_len_nbr_base_u(nb / (unsigned long)ft_strlen(base), base, len);
		ft_len_nbr_base_u(nb % (unsigned long)ft_strlen(base), base, len);
	}
	if (nb < (unsigned long)ft_strlen(base))
		*len += 1;
}
