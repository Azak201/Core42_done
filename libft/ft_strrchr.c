/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:06:19 by amismail          #+#    #+#             */
/*   Updated: 2024/08/26 16:55:06 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*strrchr(const char *s, int c)
{
	char	*ptr;

       	ptr = (char *)s + (ft_strlen(s) - 1);
	while (*ptr != 0)
	{
		if (*ptr == c)
			return(ptr);
		ptr --;
	}
	return (NULL);
}

/*int main() {
    char str[] = "hello world";
    char c = 'o';
    char *ptr = strrchr(str, c);

    if (ptr != NULL) {
        printf("Last occurrence of '%c' found at index %ld\n", c, ptr - str);
    } else {
        printf("Character '%c' not found\n", c);
    }

    return 0;
}*/
