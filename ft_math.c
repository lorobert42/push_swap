/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/10/27 15:19:51 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_mean(t_list **a)
{
	t_list	*tmp;
	int 	mean;

	mean = 0;
	tmp = *a;
	while (tmp)
	{
		mean += ft_get_c(tmp);
		tmp = tmp->next;
	}
	return (mean / ft_lstsize(*a));
}

int	ft_half_sorted(t_list **a, int mean)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (ft_get_c(tmp) < mean)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}