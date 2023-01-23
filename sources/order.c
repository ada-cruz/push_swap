/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:45:21 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/22 14:50:17 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	smallest_number(int *stacka, int x)
{
	int	i;
	int	temp;

	i = 0;
	temp = stacka[i];
	while (i < x)
	{
		if (temp > stacka[i])
			temp = stacka[i];
		i++;
	}
	return (temp);
}

int	*sort_3_number(int *stacka)
{
	int	i;

	i = 0;
	if (stacka[i] > stacka[i + 1] && stacka[i] > stacka[i + 2])
	{
		if (stacka[0] > stacka[1] && stacka[1] < stacka[2])
			rotate(&stacka, 3);
		else if (stacka[i] > stacka[i + 1] && stacka[i + 1] > stacka[i + 2])
		{
			swap(stacka, 3);
			reverse(&stacka, 3);
		}
	}
	if (stacka[i] < stacka[i + 1] && stacka[i + 1] > stacka[i + 2])
	{
		if (stacka[i] < stacka[i + 2])
		{
			swap(stacka, 3);
			rotate(&stacka, 3);
		}
		else if (stacka[i] > stacka[i + 2])
			reverse(&stacka, 3);
	}
	if (stacka[i] < stacka[i + 2] && stacka[i + 1] < stacka[i + 2])
	{
		if (stacka[i] > stacka[i + 1])
			swap(stacka, 3);
	}
	return (stacka);
}

int	*sort_5_number(int *stacka, int *stackb, int sizea, int sizeb)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = smallest_number(stacka, 5);
	while (i < 5)
	{
		if (stacka[0] == smallest)
		{
			push(&stackb, &stacka, ++sizeb, --sizea);
			break ;
		}
		rotate(&stacka, sizea);
		i++;
	}
	smallest = smallest_number(stacka, 4);
	i = 0;
	while (i < 4)
	{
		if (stacka[0] == smallest)
		{
			push(&stackb, &stacka, ++sizeb, --sizea);
			break ;
		}
		rotate(&stacka, sizea);
		i++;
	}
	stacka = sort_3_number(stacka);
	push(&stacka, &stackb, ++sizea, --sizeb);
	push(&stacka, &stackb, ++sizea, --sizeb);
	if (stackb)
		free(stackb);
	return (stacka);
}

void sort_many_numbers(int *stacka, int sizea, int *stackb, int sizeb)
{
	int amount_of_binary;
	int i;
	int j;

	amount_of_binary = bigger_binary(stacka, sizea);
	i = 0;
	while(i < amount_of_binary)
	{
		j = 0;
		while (j < sizea)
		{
			if (stacka[0] >> i & 1)
				rotate(&stacka, sizea);
				
			else
				push(&stackb, &stacka, ++sizeb, --sizea);
			j++;
		} 
		while(stackb)
			push(&stacka, &stackb, ++sizea, --sizeb);
		i++;
	}
}