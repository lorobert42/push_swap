/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 13:59:37 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	ft_is_sorted(t_stack *s)
{
	int		max;
	t_list	*tmp;

	if (!s->list)
		return (1);
	tmp = s->list;
	max = ft_get_c(tmp);
	while (tmp)
	{
		if (ft_get_c(tmp) < max)
			return (0);
		max = ft_get_c(tmp);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort(t_stack *a, t_tab *goal)
{
	if (a->size == 1)
		return ;
	else if (a->size == 2)
	{
		if (ft_get_c(a->list) > ft_get_c(a->list->next))
			ft_swap(a, 1);
		return ;
	}
	else if (a->size == 3)
		return (ft_sort_3(a));
	else if (a->size > 3 && a->size <= 10)
		return (ft_sort_small(a, goal));
	else
		return (ft_sort_large(a, goal));
}
