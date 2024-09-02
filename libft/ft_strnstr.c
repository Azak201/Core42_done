/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:43:15 by amismail          #+#    #+#             */
/*   Updated: 2024/08/27 17:42:17 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*comp;
	char	*b;

	comp = (char *)little;
	while (big && len--)
	{
		b = (char *)big;
		while ((*b == *comp) && len--)
		{
			if (*(++comp) == '\0')
				return ((char *)big);
			b++;
		}
		comp = (char *)little;
		big++;
	}
	return (NULL);
}
