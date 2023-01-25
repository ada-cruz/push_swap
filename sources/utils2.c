/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:03:59 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/25 20:33:30 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	create_stack(int **stack_a, int argc, char **argv)
{
	int		i;
	long	atoi_plus;

	i = 0;
	(*stack_a) = ft_calloc(sizeof(int), argc - 1);
	if (!(*stack_a))
		return (1);
	i = 1;
	while (argv[i] != NULL)
	{
		atoi_plus = ft_atoi_plus(argv[i]);
		if (atoi_plus == 42000000000)
		{
			free((*stack_a));
			return (error());
		}
		(*stack_a)[i - 1] = atoi_plus;
		i++;
	}
	return (0);
}

int	sort_stacks(int **stack_a, int **stack_b, int size_a, int size_b)
{
	if (size_a <= 3)
		*stack_a = sort_3_number(stack_a, size_a);
	else if (size_a <= 5)
		*stack_a = sort_5_number(stack_a, stack_b, size_a, size_b);
	else
	{
		renumber(*stack_a, size_a);
		sort_many_numbers(*stack_a, size_a, *stack_b, size_b);
		return (0);
	}
	free(*stack_a);
	return (1);
}
