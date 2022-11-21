/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:14:51 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/21 14:13:40 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	ft_sort_large(t_stack *a, t_tab *goal)
{
	t_stack	*b;
	t_tab	*chunks;
	int		down;

	if (ft_is_sorted(a))
		exit(0);
	chunks = ft_sorted_chunks(goal, a);
	if (!chunks)
		ft_error(a, goal);
	b = ft_init_stack('b');
	if (!b)
		ft_error(a, goal);
	ft_move_chunks(a, b, chunks);
	down = 0;
	while (b->size || down)
	{
		ft_move_back(a, b, goal, &down);
	}
	free(chunks->tab);
	free(chunks);
	ft_clear_stack(b);
}

void	ft_move_chunks(t_stack *a, t_stack *b, t_tab *chunks)
{
	int	i;

	i = 0;
	while (i < chunks->size)
	{
		while (ft_get_c(a->list) > chunks->tab[i])
		{
			if (ft_index_limit(a->list, chunks->tab[i]) <= \
					ft_rev_index_limit(a->list, chunks->tab[i]))
				ft_rotate(a, 1);
			else
				ft_rrotate(a, 1);
		}
		ft_push(b, a, 1);
		if (ft_get_min(a) >= chunks->tab[i])
			i++;
	}
	ft_move_last_chunk(a, b);
}

void	ft_move_last_chunk(t_stack *a, t_stack *b)
{
	while (ft_lstsize(a->list) > 3)
	{
		if (ft_index(a, ft_get_min(a)) && ft_index(a, ft_get_min(a)) <= \
				ft_rev_index(a->list, ft_get_min(a)))
			ft_rotate(a, 1);
		else if (ft_index(a, ft_get_min(a)))
			ft_rrotate(a, 1);
		else
			ft_push(b, a, 1);
	}
	ft_sort_3(a);
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
