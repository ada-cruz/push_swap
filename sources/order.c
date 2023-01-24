/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:45:21 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/24 13:56:05 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	smallest_number(int *stacka, int sizea)
{
	int	i;
	int	temp;

	i = 0;
	temp = stacka[i];
	while (i < sizea)
	{
		if (temp > stacka[i])
			temp = stacka[i];
		i++;
	}
	return (temp);
}

int	*sort_3_number(int *stacka, int sizea)
{
	if (sizea == 2)
	{
		if (stacka[0] > stacka[1])
		{
			swap(stacka, sizea);
			ft_putstr_fd("sa\n", 1);
			return (stacka);
		}
	}
	if (stacka[0] > stacka[1] && stacka[0] > stacka[2])
	{
		bignumisfirst(&stacka);
		return (stacka);
	}
	if (stacka[0] < stacka[1] && stacka[1] > stacka[2])
	{
		bignumissecond(&stacka);
		return (stacka);
	}
	if (stacka[0] < stacka[2] && stacka[1] < stacka[2])
	{
		bignumisthird(&stacka);
		return (stacka);
	}
	return (stacka);
}

int	*sort_5_number(int *stacka, int *stackb, int sizea, int sizeb)
{
	int	smallest;

	while (sizea > 3)
	{
		smallest = smallest_number(stacka, sizea);
		if (stacka[0] == smallest)
		{
			push(&stackb, &stacka, ++sizeb, --sizea);
			ft_putstr_fd("pb\n", 1);
		}
		rotate(&stacka, sizea);
		ft_putstr_fd("ra\n", 1);
	}
	stacka = sort_3_number(stacka, sizea);
	push(&stacka, &stackb, ++sizea, --sizeb);
	ft_putstr_fd("pa\n", 1);
	if (sizeb)
	{
		push(&stacka, &stackb, ++sizea, --sizeb);
		ft_putstr_fd("pa\n", 1);
	}
	if (stackb)
		free(stackb);
	return (stacka);
}

void	sort_many_numbers(int *stacka, int sizea, int *stackb, int sizeb)
{
	int	amount_of_binary;
	int	i;
	int	j;

	amount_of_binary = bigger_binary(stacka, sizea);
	i = 0;
	while (i++ < amount_of_binary)
	{
		j = 0;
		while (j++ < sizea)
		{
			if (stacka[0] >> (i - 1) & 1)
			{
				rotate(&stacka, sizea);
				ft_putstr_fd("ra\n", 1);
			}
			else
			{
				push(&stackb, &stacka, ++sizeb, --sizea);
				ft_putstr_fd("pb\n", 1);
			}
		}
		backtoa(&stacka, &stackb, sizea, sizeb);
	}
	free(stacka);
}
