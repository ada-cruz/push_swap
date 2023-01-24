/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatestack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:04:01 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/24 15:12:58 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	itsorganized(int *stacka,int sizea)
{
	int i;

	i = 0;
	
	while(i < sizea - 1)
	{	
		if (stacka[i] > stacka[i + 1])
			return (0);
		i++;
	}
	return (1);
}