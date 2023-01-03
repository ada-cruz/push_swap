/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:09:15 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/03 10:55:21 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "./library/libft/libft.h"


void swap(int *stack, int stacksize)
{
    int aux;
    
    if (stacksize <= 1)
        return ;
    aux = stack[0];
    stack[0] = stack[1];
    stack[1] = aux;
}

void swapswap(int *stack_a, int *stack_b, int sizea, int sizeb)
{
    swap(stack_a, sizea);
    swap(stack_b, sizeb);
}

void push(int *dest, int *origin, int sizedest)
{
    int i;
    i = 0;
    
    while(i < sizedest)
    {
        dest[i] = dest[i + 1];
        i++;
    }
    dest[0] = origin[0];
}

int main(int argc, char **argv)
{
    int i;
    int *stack_a;
    int stack_b[4] = {2, 1, 4, 5};

        if (argc <= 1)
        {
                write(1, "Error\n", 6);
                return (1);
        }
    stack_a = malloc((sizeof(int) * argc - 1));
    if (!stack_a)
        return (1);
    // stack_b = malloc((sizeof(int) * argc -1));
    // if (!stack_b)
    //     return (1);
    i = 1;
    while (argv[i] != NULL)
    {
        stack_a[i - 1] = ft_atoi(argv[i]);
        i++;
    }
    push(stack_a, stack_b);
    // int z = 0;
    // while(z < argc - 1)
    // {
    //     printf("%d\n", stack_a[z]);
    //     z++;
    // }
}
//obs, tratar numeros iguais passados de argumentos.