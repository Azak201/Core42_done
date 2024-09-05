/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:28:11 by amismail          #+#    #+#             */
/*   Updated: 2024/09/05 22:29:40 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	x;
	size_t	slen;

	if (s == NULL || f == NULL)
		return ;
	slen = ft_strlen(s);
	x = 0;
	while (s[x] != '\0')
	{
		f((unsigned int)x, &s[x]);
		x++;
	}
}
