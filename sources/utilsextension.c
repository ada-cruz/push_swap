/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsextension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:47:02 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/23 23:51:27 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bignumisfirst(int **stacka)
{
	if (*stacka[0] > *stacka[1] && *stacka[0] > *stacka[2])
	{
		if (*stacka[0] > *stacka[1] && *stacka[1] < *stacka[2])
		{
			rotate(stacka, 3);
			ft_putstr_fd("ra\n", 1);
		}
		else if (*stacka[0] > *stacka[1] && *stacka[1] > *stacka[2])
		{
			swap(*stacka, 3);
			ft_putstr_fd("sa\n", 1);
			reverse(stacka, 3);
			ft_putstr_fd("rra\n", 1);
		}
	}
}

void	bignumissecond(int **stacka)
{
	if (*stacka[0] < *stacka[2])
	{
		swap(*stacka, 3);
		ft_putstr_fd("sa\n", 1);
		rotate(stacka, 3);
		ft_putstr_fd("ra\n", 1);
	}
	else if (*stacka[0] > *stacka[2])
	{
		reverse(stacka, 3);
		ft_putstr_fd("rra\n", 1);
	}
}

void	bignumisthird(int **stacka)
{
	if (*stacka[0] > *stacka[1])
	{
		swap(*stacka, 3);
		ft_putstr_fd("sa\n", 1);
	}
}

void	backtoa(int **stacka, int **stackb,int sizea,int sizeb)
{
	while (*stackb)
	{
		push(stacka, stackb, ++sizea, --sizeb);
		ft_putstr_fd("pa\n", 1);
	}
}