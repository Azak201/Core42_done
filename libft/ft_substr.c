/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:23:43 by amismail          #+#    #+#             */
/*   Updated: 2024/08/31 12:23:49 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*substr;
	char	*dup;

	dup = (char *)(s + start);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	substr = sub;
	while (*dup != '\0' && len--)
	{
		*sub++ = *dup++;
	}
	if (*sub != '\0')
		*++sub = '0';
	return (substr);
}
/*int main()
{
    char a[20] = "amjed test the loc";
    char *b;

    b = ft_substr(a, 2, 10);
    printf("%s \n", b);

    return 0;
}*/