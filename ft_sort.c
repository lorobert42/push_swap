/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:19:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/22 12:15:21 by lorobert         ###   ########.fr       */
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

void	ft_move_back(t_stack *a, t_stack *b, t_tab *sorted, int *n_down)
{
	if ((b->size && ft_sorted_index(sorted, ft_get_c(ft_lstlast(a->list))) == \
			ft_sorted_index(sorted, ft_get_c(a->list)) - 1) || \
			(!b->size && *n_down))
	{
		ft_rrotate(a, 1);
		(*n_down)--;
	}
	else if (b->size && ft_index(b, ft_get_max(b)) == 0)
		ft_push(a, b, 1);
	else if (*n_down == 0 || ft_get_c(b->list) > ft_get_c(ft_lstlast(a->list)))
	{
		ft_push(a, b, 1);
		ft_rotate(a, 1);
		(*n_down)++;
	}
	else if (ft_index(b, ft_get_max(b)) <= ft_rev_index(b->list, ft_get_max(b)))
		ft_rotate(b, 1);
	else
		ft_rrotate(b, 1);
}
