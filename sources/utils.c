/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:50:21 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/25 17:19:38 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	renumber(int *stacka, int sizea)
{
	int	i;
	int	*operatedstack;
	int	j;

	operatedstack = ft_calloc(sizeof (int), sizea);
	if (!operatedstack)
		return ;
	i = 0;
	while (i < sizea)
	{
		j = 0;
		operatedstack[i] = 0;
		while (j < sizea)
		{
			if (stacka[i] > stacka[j])
				operatedstack[i] = operatedstack[i] + 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i++ < sizea)
		stacka[i - 1] = operatedstack[i - 1];
	if (operatedstack)
		free (operatedstack);
}

int	bigger_binary(int sizea)
{
	int	bigger_num;
	int	amount_of_binary;

	bigger_num = sizea - 1;
	amount_of_binary = 0;
	while (bigger_num > 0)
	{
		bigger_num = bigger_num / 2;
		amount_of_binary++;
	}
	return (amount_of_binary);
}

int	error(void)
{
	ft_putstr_fd ("Error\n", 2);
	return (1);
}
