/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:50:21 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/22 16:26:53 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    renumber(int *stacka,int sizea)
{
	int newnumber;
	int i;
	int *operatedstack;
	int j;

	operatedstack = malloc(sizeof  (int) * sizea);
	if (!operatedstack)
		return ;
	newnumber = 0;
	i = 0;
	while (i < sizea)
	{
		newnumber = 0;
		j = 0;
		while(j < sizea)
		{
			if (stacka[i] > stacka[j])
				newnumber++;
			j++;
		}
		operatedstack[i] = newnumber;
		i++;
	}
	i = 0;
	while(i < sizea)
	{
		stacka[i] = operatedstack[i];
		i++;
	}
	if(operatedstack)
		free (operatedstack);
}

int bigger_binary(int *stacka, int sizea)
{
	int i;
	int bigger_num;
	int amount_of_binary;
	
	i = 1;
	bigger_num = stacka[0];
	amount_of_binary = 0;
	while (i < sizea)
	{
		if (stacka[i] > bigger_num)
			bigger_num = stacka[i];
		i++;
	}
	while (bigger_num > 0)
	{
		bigger_num = bigger_num / 2;
		amount_of_binary++;
	}
	return (amount_of_binary);
}
