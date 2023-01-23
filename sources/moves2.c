/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:44:12 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/24 00:08:11 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int *stack, int stacksize)
{
	int	aux;

	if (stacksize <= 1)
		return ;
	aux = stack[0];
	stack[0] = stack[1];
	stack[1] = aux;
}

void	rotate(int **stack, int sizestack)
{
	int	i;
	int	*updated_stack;
	int	*temp;

	if (sizestack <= 1)
		return ;
	i = 0;
	temp = *stack;
	updated_stack = ft_calloc(sizeof(int) , sizestack);
	if (!updated_stack)
		return ;
	while (i < sizestack - 1)
	{
		updated_stack[i] = temp[i + 1];
		i++;
	}
	updated_stack[sizestack - 1] = temp[0];
	if (*stack)
		free (*stack);
	*stack = updated_stack;
}

void	reverse(int **stack, int sizestack)
{
	int	i;
	int	*updated_stack;
	int	*temp;

	if (sizestack <= 1)
		return ;
	i = 1;
	temp = *stack;
	updated_stack = malloc(sizeof(int) * sizestack);
	if (!updated_stack)
		return ;
	while (i < sizestack - 1)
	{
		updated_stack[i] = temp[i - 1];
		i++;
	}
	updated_stack[0] = temp[sizestack - 1];
	if (*stack)
		free (*stack);
	*stack = updated_stack;
}
