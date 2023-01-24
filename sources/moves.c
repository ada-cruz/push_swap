/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:35:22 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/24 01:30:30 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_stack_a(int *dest, int *origin, int size)
{
	int	i;

	i = 0;
	if (!origin)
		return ;
	while (i < size)
	{
		dest[i] = origin[i + 1];
		i++;
	}
}

void	update_stack_b(int *dest, int *origin, int size)
{
	int	i;

	i = 0;
	if (!origin)
		return ;
	while (i < size - 1)
	{
		dest[i + 1] = origin[i];
		i++;
	}
}

void	push(int **dest, int **origin, int sizedest, int sizeorigin)
{
	int	*updated_dest;
	int	*updated_origin;

	if (sizedest > 0)
		updated_dest = ft_calloc(sizedest, sizeof(int));
	else
		updated_dest = NULL;
	if (sizeorigin > 0)
		updated_origin = ft_calloc(sizeorigin, sizeof(int));
	else
		updated_origin = NULL;
	update_stack_a(updated_origin, *origin, sizeorigin);
	update_stack_b(updated_dest, *dest, sizedest);
	updated_dest[0] = *origin[0];
	if (*dest)
		free (*dest);
	if (*origin)
		free (*origin);
	*origin = updated_origin;
	*dest = updated_dest;
}
