/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:42:26 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/25 20:28:22 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <stdlib.h>
# include <unistd.h>
# include "../library/libft/libft.h"

void	swap(int *stack, int stacksize);
void	rotate(int **stack, int sizestack);
void	reverse(int **stack, int sizestack);
void	update_stack_a(int *dest, int *origin, int size);
void	update_stack_b(int *dest, int *origin, int size);
void	push(int **dest, int **origin, int sizedest, int sizeorigin);
void	renumber(int *stacka, int sizea);
void	sort_many_numbers(int *stk_a, int sizea, int *stk_b, int sizeb);
void	bignumisfirst(int **stacka);
void	bignumissecond(int **stacka);
void	bignumisthird(int **stacka);
void	backtoa(int **stacka, int **stackb, int *sizea, int *sizeb);
int		create_stack(int **stack_a, int argc, char **argv);
int		smallest_number(int *stacka, int x);
int		*sort_3_number(int **stacka, int sizea);
int		*sort_5_number(int **stacka, int **stackb, int sizea, int sizeb);
int		bigger_binary(int sizea);
int		itsorganized(int *stacka, int sizea);
int		itsallnum(char **argv);
int		error(void);
int		norepeatednum(int *stacka, int sizea);
long	ft_atoi_plus(const char *nptr);
int		sort_stacks(int **stack_a, int **stack_b, int size_a, int size_b);

#endif