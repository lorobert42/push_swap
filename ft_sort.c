/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 11:16:04 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	ft_is_sorted(t_list *a)
{
	int		max;

	if (!a)
		return (1);
	max = ft_get_c(a);
	while (a)
	{
		if (ft_get_c(a) < max)
			return (0);
		max = ft_get_c(a);
		a = a->next;
	}
	return (1);
}

void	ft_sort(t_stack *a, t_tab *sorted)
{
	if (a->size == 1)
		return ;
	else if (a->size == 2)
	{
		if (ft_get_c(a->values) > ft_get_c(a->values->next))
			ft_swap(a, 1);
		return ;
	}
	else if (a->size == 3)
		return (ft_sort_3(a));
	else if (a->size > 3 && a->size <= 10)
		return (ft_sort_small(a, sorted));
	else
		return (ft_sort_large(a, sorted));
}
