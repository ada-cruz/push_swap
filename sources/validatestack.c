/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatestack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:04:01 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/01/25 14:10:28 by ada-cruz         ###   ########.fr       */
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

int itsallnum(char **argv)
{
	int		only_numbers;
	int		column;
	char 	*trim;

	only_numbers = 0;
	while(argv[0] && only_numbers == 0)
	{
		trim = ft_strtrim(argv[0], " ");
		if (!trim || !*trim)
			only_numbers = 1;
		column = 0;
		while (trim[column] && only_numbers == 0)
		{
			if ((ft_isdigit(trim[column]) == 0 
            && ((trim[column] != '-' && trim[column] != '+') || column != 0)) \
            || ((trim[column] == '-' || trim[column] == '+') \
            && trim[column + 1] == '\0'))
				only_numbers = 1;
			column++;
		}
		free(trim);
		argv++;
	}
	return(only_numbers);
}

long	ft_atoi_plus(const char *nptr)
{
    long    result;
    int        sign;

    result = 0;
    sign = 1;
    while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
        nptr++;
    if (*nptr == '+' || *nptr == '-')
    {
        if (*nptr == '-')
            sign = -1;
        nptr++;
    }
    while (ft_isdigit(*nptr))
    {
        result = result * 10 + (*nptr - '0');
        if (result * sign < INT_MIN || result * sign > INT_MAX)
        {
            return (42000000000);
        }
        nptr++;
    }
    return (result * sign);
}

int	norepeatednum(int *stacka,int sizea)
{
	int i;
	int j;

	i = 0;
	while(i < sizea)
	{
		j = i + 1;
		while(j < sizea)
		{
			if (stacka[i] == stacka[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}