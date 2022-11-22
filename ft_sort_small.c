/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:14:19 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/22 12:15:26 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *a)
{
	if (ft_is_sorted(a))
		return ;
	if (ft_get_c(a->list) == ft_get_min(a))
	{
		ft_swap(a, 1);
		ft_rotate(a, 1);
	}
	else if (ft_get_c(a->list) == ft_get_max(a) && \
			ft_get_c(a->list->next) == ft_get_min(a))
		ft_rotate(a, 1);
	else if (ft_get_c(a->list) == ft_get_max(a))
	{
		ft_swap(a, 1);
		ft_rrotate(a, 1);
	}
	else if (ft_get_c(a->list->next) == ft_get_min(a))
		ft_swap(a, 1);
	else
		ft_rrotate(a, 1);
}

void	ft_sort_small(t_stack *a, t_tab *sorted)
{
	t_stack	*b;
	int		down;

	if (ft_is_sorted(a))
		return ;
	b = ft_init_stack('b');
	if (!b)
		ft_error(a, sorted);
	while (a->size > 3)
	{
		if (ft_get_c(a->list) <= sorted->tab[sorted->size - 4])
			ft_push(b, a, 1);
		else
			ft_rotate(a, 1);
	}
	ft_sort_3(a);
	down = 0;
	while (b->size || down)
	{
		ft_move_back(a, b, sorted, &down);
	}
	ft_clear_stack(b);
}
