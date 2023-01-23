/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:45:21 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/24 00:00:59 by ada-cruz         ###   ########.fr       */
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

int	*sort_3_number(int **stacka, int sizea)
{
	if (sizea == 2)
	{
		if (*stacka[0] > *stacka[1])
		{
			swap(*stacka, 2);
			ft_putstr_fd("sa\n", 1);
			return (*stacka);
		}
	}
	if (*stacka[0] > *stacka[1] && *stacka[0] > *stacka[2])
	{
		printf("\n%d\n", *stacka[0]);
		printf("\n%d\n", *stacka[1]);
		printf("\n%d\n", *stacka[2]);
		write(1,"\naqui\n", 6);
		bignumisfirst(stacka);
		return (*stacka);
	}
	if (*stacka[0] < *stacka[1] && *stacka[1] > *stacka[2])
	{
		bignumissecond(stacka);
		return (*stacka);
	}
	if (*stacka[0] < *stacka[2] && *stacka[1] < *stacka[2])
	{
		bignumisthird(stacka);
		return (*stacka);
	}
	return (*stacka);
}

int	*sort_5_number(int *stacka, int *stackb, int sizea, int sizeb)
{
	int	i;
	int	smallest;

	i = 0;
	while (sizea > 3)
	{
		smallest = smallest_number(stacka, sizea);
		if (stacka[0] == smallest)
		{
			push(&stackb, &stacka, ++sizeb, --sizea);
			ft_putstr_fd("pb\n", 1);
			break ;
		}
		rotate(&stacka, sizea);
		ft_putstr_fd("ra\n", 1);
	}
	sort_3_number(&stacka, sizea);
	push(&stacka, &stackb, ++sizea, --sizeb);
	ft_putstr_fd("pa\n", 1);
	//push(&stacka, &stackb, ++sizea, --sizeb);
	//ft_putstr_fd("pa\n", 1);
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
