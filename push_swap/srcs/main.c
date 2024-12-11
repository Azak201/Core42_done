/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:53:01 by amismail          #+#    #+#             */
/*   Updated: 2024/12/04 16:53:11 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

int main(int arc, char **arv)
{
	char **inputs;
	// int i;
	inputs = spliter(arc, arv);
	if (!inputs)
		ft_exit(1, NULL);

	//  i = 0;
	// while (inputs[i])
	// printf("%s \n", inputs[i++]);
	handler(inputs);
	inserter(inputs);
	ft_exit(3, inputs);
}
