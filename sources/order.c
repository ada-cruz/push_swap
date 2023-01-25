/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:45:21 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/25 20:30:28 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	small_num_position(int *stacka, int sizea)
{
	int	i;
	int	temp;

	i = 0;
	temp = i;
	while (i < sizea)
	{
		if (stacka[temp] > stacka[i])
			temp = i;
		i++;
	}
	return (temp);
}

void	pre_sort_5_num(int **stacka, int **stackb, int *sizea, int *sizeb)
{
	int	small_pos;

	while (*sizea > 3)
	{
		small_pos = small_num_position(*stacka, *sizea);
		if (small_pos == 0)
		{
			push(stackb, stacka, ++(*sizeb), --(*sizea));
			ft_putstr_fd("pb\n", 1);
		}
		else if (small_pos <= 2)
		{
			rotate(stacka, *sizea);
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			reverse(stacka, *sizea);
			ft_putstr_fd("rra\n", 1);
		}	
	}
}

int	*sort_3_number(int **stacka, int sizea)
{
	if (sizea == 2)
	{
		if ((*stacka)[0] > (*stacka)[1])
		{
			swap(*stacka, sizea);
			ft_putstr_fd("sa\n", 1);
			return (*stacka);
		}
	}
	if ((*stacka)[0] > (*stacka)[1] && (*stacka)[0] > (*stacka)[2])
	{
		bignumisfirst(stacka);
		return (*stacka);
	}
	if ((*stacka)[0] < (*stacka)[1] && (*stacka)[1] > (*stacka)[2])
	{
		bignumissecond(stacka);
		return (*stacka);
	}
	if ((*stacka)[0] < (*stacka)[2] && (*stacka)[1] < (*stacka)[2])
	{
		bignumisthird(stacka);
		return (*stacka);
	}
	return (*stacka);
}

int	*sort_5_number(int **stacka, int **stackb, int sizea, int sizeb)
{
	pre_sort_5_num(stacka, stackb, &sizea, &sizeb);
	*stacka = sort_3_number(stacka, sizea);
	push(stacka, stackb, ++sizea, --sizeb);
	ft_putstr_fd("pa\n", 1);
	if (sizeb)
	{
		push(stacka, stackb, ++sizea, --sizeb);
		ft_putstr_fd("pa\n", 1);
	}
	if (*stackb)
		free(*stackb);
	return (*stacka);
}

void	sort_many_numbers(int *stk_a, int sizea, int *stk_b, int sizeb)
{
	int	amount_of_binary;
	int	i;
	int	j;

	amount_of_binary = bigger_binary(sizea);
	i = 0;
	while (i++ < amount_of_binary)
	{
		j = 0;
		while (j++ < sizea + sizeb)
		{
			if (stk_a[0] >> (i - 1) & 1)
			{
				rotate(&stk_a, sizea);
				ft_putstr_fd("ra\n", 1);
			}
			else
			{
				push(&stk_b, &stk_a, ++sizeb, --sizea);
				ft_putstr_fd("pb\n", 1);
			}
		}
		backtoa(&stk_a, &stk_b, &sizea, &sizeb);
	}
	free(stk_a);
}
