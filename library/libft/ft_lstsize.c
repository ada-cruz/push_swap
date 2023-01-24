/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:49:28 by ada-cruz          #+#    #+#             */
/*   Updated: 2022/09/25 01:59:18 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_lstsize(t_list *lst)
{
	int	countnode;
	
	countnode = 0
	while (lst != NULL)
	{
		countnode++
		lst = lst -> next;
	}
	return (countnode);
}