/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:09:15 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/04 18:48:47 by ada-cruz         ###   ########.fr       */
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

int *push(int *dest, int *origin, int sizedest, int sizeorigin)
{
    int i;
    int *updated_dest;

    if (sizeorigin < 1)
        return (NULL);
    i = 0;
    updated_dest = malloc(sizeof(int) * sizedest);
    while (i < sizedest - 1)
    {
        updated_dest[i + 1] = dest[i];
        i++;
    }
    updated_dest[0] = origin[0];
    free (dest);
    return (updated_dest);
}

void    rotate(int **stack, int sizestack)
{
    int i;
    int *updated_stack;
    int *temp;
    
    i = 0;
    temp = *stack;
    updated_stack = malloc(sizeof(int) * sizestack);
    if(!updated_stack)
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

void    rotaterotate(int **stacka, int **stackb, int sizea, int sizeb)
{
    rotate(stacka, sizea);
    rotate(stackb, sizeb);
}

void    reverse(int **stack, int sizestack)
{
    int i;
    int *updated_stack;
    int *temp;
    
    i = 1;
    temp = *stack;
    updated_stack = malloc(sizeof(int) * sizestack);
    if(!updated_stack)
        return ;
    while (i < sizestack)
    {
        updated_stack[i] = temp[i - 1];
        i++;
    }
    updated_stack[0] = temp[sizestack - 1];
    if (*stack)
        free (*stack);
    *stack = updated_stack;
}

void    reversereverse(int **stacka, int **stackb, int sizea, int sizeb)
{
    reverse(stacka, sizea);
    reverse(stackb, sizeb);
}

int main(int argc, char **argv)
{
    int i;
    int *stack_a;
    int *stack_b;

    stack_a = malloc(sizeof(int) * 4);
    stack_a[0] = 1;
    stack_a[1] = 2;
    stack_a[2] = 3;
    stack_a[3] = 4;
    
    stack_b = malloc(sizeof(int) * 4);
    stack_b[0] = 5;
    stack_b[1] = 4;
    stack_b[2] = 2;
    stack_b[3] = 1;

    //swap(stack_b, 4);
    //swapswap(stack_a, stack_b, 4, 4);
    //push(stack_b, stack_a, 4, 4);
    //rotate(&stack_a, 4);
    //rotate(&stack_b, 4);
    //rotaterotate(&stack_a, &stack_b, 4, 4);
    //reverse(&stack_a, 4);
    //reverse(&stack_b, 4);
    //reversereverse(&stack_a, &stack_b, 4, 4);
    
    int y = 0;
    printf("stack a\n");
    while(y < 4)
    {
         printf("%d\n", stack_a[y]);
         y++;
    }
    int z = 0;
    printf("\n stack b\n");
    while(z < 4)
    {
        printf("%d\n", stack_b[z]);
         z++;
    }
    if(stack_a)
        free(stack_a);
    if(stack_b)
        free(stack_b);
        // if (argc <= 1)
        // {
        //         write(1, "Error\n", 6);
        //         return (1);
        // }
    //stack_a = malloc((sizeof(int) * argc - 1));
    //if (!stack_a)
    //    return (1);
    // stack_b = malloc((sizeof(int) * argc -1));
    // if (!stack_b)
    //     return (1);
    //i = 1;
    //while (argv[i] != NULL)
    // {
    //     stack_a[i - 1] = ft_atoi(argv[i]);
    //     i++;
    // }

}
//obs, tratar numeros iguais passados de argumentos.