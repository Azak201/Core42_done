/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:09:26 by amismail          #+#    #+#             */
/*   Updated: 2024/08/28 15:30:08 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	dsize;
	int	ssize;

	dsize = ft_strlen(dst);
	ssize = ft_strlen(src);
	if ((dsize + ssize + 1 > size))
	{
		ft_memcpy(dst + dsize, src, size - dsize - 1);
		dst[size - 1] = '\0';
		return (size - 1);
	}
	ft_memcpy(dst + dsize, src, ssize);
	return (ssize + dsize);
}
/*int main(void)
{
	char dest[10] = "Hello";
	char src[] = " World";
	size_t len;
	len = ft_strlcat(dest, src, sizeof(dest));
	printf("%s\n", dest);
	printf("len: %zu\n", len);

	return 0;
}*/
