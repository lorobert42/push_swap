/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:14:19 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 11:29:18 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *a)
{
	if (ft_is_sorted(a->values))
		return ;
	if (ft_get_c(a->values) == ft_get_min(a->values))
	{
		ft_swap(a, 1);
		ft_rotate(a, 1);
	}
	else if (ft_get_c(a->values) == ft_get_max(a->values) && \
			ft_get_c(a->values->next) == ft_get_min(a->values))
		ft_rotate(a, 1);
	else if (ft_get_c(a->values) == ft_get_max(a->values))
	{
		ft_swap(a, 1);
		ft_rrotate(a, 1);
	}
	else if (ft_get_c(a->values->next) == ft_get_min(a->values))
		ft_swap(a, 1);
	else
		ft_rrotate(a, 1);
}

void	ft_sort_small(t_stack *a, t_tab *sorted)
{
	t_stack	*b;

	if (ft_is_sorted(a->values))
		return ;
	b = ft_init_stack('b');
	if (!b)
		ft_error(a, sorted);
	while (a->size > 3)
		ft_push(b, a);
	ft_sort_3(a);
	while (b->size)
	{
		while (ft_find_position(ft_get_c(b->values), a->values) <= a->size / 2)
			ft_rotate(a, 1);
		while (ft_find_position(ft_get_c(b->values), a->values) > a->size / 2)
			ft_rrotate(a, 1);
		ft_push(a, b);
	}
	while (ft_index(a->values, ft_get_min(a->values)) <= a->size / 2)
		ft_rotate(a, 1);
	while (ft_index(a->values, ft_get_min(a->values)) > a->size / 2)
		ft_rrotate(a, 1);
	ft_clear_stack(b);
}
