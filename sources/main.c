/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:09:15 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/24 15:14:51 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;

	if (argc <= 1)
		return (0);
	stack_a = ft_calloc(sizeof(int) , argc - 1);
	stack_b = NULL;
	if (!stack_a)
		return (1);
	i = 1;
	while (argv[i] != NULL)
	{
		stack_a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	size_a = argc - 1;
	size_b = 0;
	
	if (itsorganized(stack_a, size_a))
	{
		free(stack_a);
		return (0);
	}
	if (size_a <= 3)
		stack_a = sort_3_number(stack_a, size_a);
	//stack_a = sort_5_number(stack_a, stack_b, size_a, size_b);
	//renumber(stack_a, size_a);
	//sort_many_numbers(stack_a, size_a, stack_b, size_b);
	free(stack_a);
}
