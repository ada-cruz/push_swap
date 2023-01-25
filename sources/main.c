/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:09:15 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/25 14:14:21 by ada-cruz         ###   ########.fr       */
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
	long	atoi_plus;

	if (argc <= 1)
		return (0);
	if (itsallnum(&argv[1]) == 1)
		return  (error());
	stack_a = ft_calloc(sizeof(int) , argc - 1);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	i = 1;
	while (argv[i] != NULL)
	{
		atoi_plus = ft_atoi_plus(argv[i]);
		if (atoi_plus == 42000000000)
		{
			free(stack_a);
			return (error());
		}
		stack_a[i - 1] = atoi_plus;
		i++;
	}
	size_a = argc - 1;
	size_b = 0;
	if (!norepeatednum(stack_a, size_a))
	{
		free (stack_a);
		return (error());
	}
	if (itsorganized(stack_a, size_a))
	{
		free(stack_a);
		return (1);
	}
	if (size_a <= 3)
		stack_a = sort_3_number(stack_a, size_a);
	else if (size_a <= 5)
	stack_a = sort_5_number(stack_a, stack_b, size_a, size_b);
	else
	{
		renumber(stack_a, size_a);
		sort_many_numbers(stack_a, size_a, stack_b, size_b);
		return (0);
	}
	free(stack_a);
}
