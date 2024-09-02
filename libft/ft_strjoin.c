/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:46:29 by amismail          #+#    #+#             */
/*   Updated: 2024/09/02 18:17:35 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len1);
	ft_strlcat(str, s2, (len1 + len2 + 1));
	return (str);
}
/*int main()
{
    char *str1 = "hello my test";
    char *str2 = " worldthis is my codde";
    char *result;

    result = ft_strjoin(str1, str2);
    printf("%s\n", result);

    free(result); // Don't forget to free the allocated memory

    return 0;
}*/
