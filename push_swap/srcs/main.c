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

static void inserter(char **inputs);

int main(int arc, char **arv)
{
	char **inputs;
	int i;
	inputs = spliter(arc, arv);
	if (!inputs)
		ft_exit(1, NULL);

	i = 0;
	while (inputs[i])
		printf("%s \n", inputs[i++]);
	handler(inputs);
	inserter(inputs);
	ft_exit(3, inputs);
}

static void print(long *cont)
{
	printf("%ld\n", *cont);
}
static void inserter(char **inputs)
{
	int i;
	long *num;
	t_dlist *stack;
	t_dlist *item;

	i = 0;
	num = (long *)malloc(sizeof(long));
	if (!num || !inputs)
		ft_exit(1, NULL);
	*num = ft_latoi(inputs[i++]);
	stack = ft_dlstnew(num);
	while (inputs[i])
	{
		num = (long *)malloc(sizeof(long));
		*num = ft_latoi(inputs[i]);
		item = ft_dlstnew(num);
		ft_dlstadd_back(&stack, item);
		i++;
	}
	ft_dlstiter(stack, print);
}
