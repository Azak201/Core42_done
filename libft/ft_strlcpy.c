/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:42:10 by amismail          #+#    #+#             */
/*   Updated: 2024/09/02 18:18:23 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*ptr;
	int		count;

	ptr = dst;
	count = 0;
	while (size-- && ptr && src)
	{
		*ptr++ = *src++;
		count++;
	}
	*ptr = '\0';
	return (count);
}