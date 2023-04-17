/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:41:55 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/17 10:52:38 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		x;

	if (s1 && s2)
	{	
		len_s1 = ft_strlen((char *)s1);
		len_s2 = ft_strlen((char *)s2);
		str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
		ft_bzero(str, len_s1 + len_s2 + 1);
		if (!str)
			return (0);
		strcpy(str, (char *)s1);
		strcat(str, (char *)s2);
		return (str);
	}
	return (NULL);
}
