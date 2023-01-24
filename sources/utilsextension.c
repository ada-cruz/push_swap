/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsextension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:47:02 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/24 01:31:44 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bignumisfirst(int **stacka)
{
	int	*stk;

	stk = *stacka;
	if (stk[0] > stk[1] && stk[0] > stk[2])
	{
		if (stk[0] > stk[1] && stk[1] < stk[2])
		{
			rotate(&stk, 3);
			ft_putstr_fd("ra\n", 1);
		}
		else if (stk[0] > stk[1] && stk[1] > stk[2])
		{
			swap(stk, 3);
			ft_putstr_fd("sa\n", 1);
			reverse(&stk, 3);
			ft_putstr_fd("rra\n", 1);
		}
	}
	*stacka = stk;
}

void	bignumissecond(int **stacka)
{
	int	*stk;

	stk = *stacka;
	if (stk[0] < stk[2])
	{
		swap(stk, 3);
		ft_putstr_fd("sa\n", 1);
		rotate(&stk, 3);
		ft_putstr_fd("ra\n", 1);
	}
	else if (stk[0] > stk[2])
	{
		reverse(&stk, 3);
		ft_putstr_fd("rra\n", 1);
	}
	*stacka = stk;
}

void	bignumisthird(int **stacka)
{
	int	*stk;

	stk = *stacka;
	if (stk[0] > stk[1])
	{
		swap(stk, 3);
		ft_putstr_fd("sa\n", 1);
	}
	*stacka = stk;
}

void	backtoa(int **stacka, int **stackb, int sizea, int sizeb)
{
	while (*stackb)
	{
		push(stacka, stackb, ++sizea, --sizeb);
		ft_putstr_fd("pa\n", 1);
	}
}
