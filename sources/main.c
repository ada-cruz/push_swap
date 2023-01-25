/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:09:15 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/25 20:33:01 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;

	stack_b = NULL;
	if (argc <= 1)
		return (0);
	if (itsallnum(&argv[1]) == 1)
		return (error());
	size_a = argc - 1;
	size_b = 0;
	if (create_stack(&stack_a, argc, argv))
		return (1);
	if (norepeatednum(stack_a, size_a))
	{
		free (stack_a);
		return (error());
	}
	if (itsorganized(stack_a, size_a))
	{
		free(stack_a);
		return (0);
	}
	sort_stacks(&stack_a, &stack_b, size_a, size_b);
}
