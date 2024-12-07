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

static char **spliter(int arc, char **arv);
static void handler(char **inputs);
static void ft_exit();
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

// -------------------------------------------------------------------------

static char **spliter(int arc, char **arv)
{
	char **tmp;
	int i;

	if (arc <= 1)
		ft_exit(1, NULL);
	else if (arc == 2)
		tmp = ft_split(arv[1], ' ');
	else
	{
		i = 0;
		tmp = (char **)malloc(sizeof(char *) * arc);
		if (!tmp)
			ft_exit(1, NULL);
		while (++i < arc)
		{
			tmp[i - 1] = ft_strdup(arv[i]);
			if (!tmp[i - 1])
				ft_exit(2, tmp);
		}
		tmp[i - 1] = NULL;
	}
	if (!tmp)
		ft_exit(1, NULL);
	return (tmp);
}

//-----------------------------------------------------------------------------

static void handler(char **inputs)
{
	int i;

	i = 0;
	while (inputs[i])
	{
		if ((ft_is_numric(inputs[i])))
			ft_exit(2, inputs);
		i++;
	}
	if ((ft_is_in_bound(inputs)))
		ft_exit(2, inputs);
	if ((ft_is_uniquenum(inputs)))
		ft_exit(2, inputs);
}

//-----------------------------------------------------------------------------
void print(double cont)
{
	printf("%ld", cont);
}
static void inserter(char **inputs)
{
	int i;
	t_list *stack;
	t_list *item;

	i = 0;
	if (!inputs)
		ft_exit(1, NULL);
	while (inputs[i])
	{
		item = ft_lstnew(inputs[i]);
		ft_lstadd_back(&stack, item);
		i++;
	}
	ft_lstiter(stack, print);
}

//-----------------------------------------------------------------------------
static void ft_exit(int flag, char **str)
{
	int i;

	i = 0;
	if (flag == 1)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	else
	{
		if (str)
		{
			while (str[i])
				free(str[i++]);
			free(str);
		}
		if (flag == 2)
			ft_putstr_fd("Error\n", 1);
		else
			ft_putstr_fd("Done\n", 1);
		exit(1);
	}
}
