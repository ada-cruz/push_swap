/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:42:26 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/23 23:52:09 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../library/libft/libft.h"

void	swap(int *stack, int stacksize);
void	rotate(int **stack, int sizestack);
void	reverse(int **stack, int sizestack);
void	update_stack_a(int *dest, int *origin, int size);
void	update_stack_b(int *dest, int *origin, int size);
void	push(int **dest, int **origin, int sizedest, int sizeorigin);
int		smallest_number(int *stacka, int x);
int		*sort_3_number(int **stacka, int sizea);
int		*sort_5_number(int *stacka, int *stackb, int sizea, int sizeb);
void	renumber(int *stacka, int sizea);
int		bigger_binary(int *stacka, int sizea);
void	sort_many_numbers(int *stacka, int sizea, int *stackb, int sizeb);
void	bignumisfirst(int **stacka);
void	bignumissecond(int **stacka);
void	bignumisthird(int **stacka);
void	backtoa(int **stacka, int **stackb,int sizea,int sizeb);

#endif